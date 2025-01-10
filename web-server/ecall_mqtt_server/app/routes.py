from flask import Blueprint, render_template, jsonify
from app.database import connect_to_db
from flask import Blueprint, request, jsonify, current_app
import json
import socketio
from datetime import datetime
from app import socketio  # Sử dụng socketio từ __init__.py



bp = Blueprint('routes', __name__)

@bp.route('/')
def home():
    # Giao diện chính
    return render_template('index.html')

@bp.route('/data')
def get_client_data():
    try:
        # Lấy dữ liệu từ MySQL
        db_connection = connect_to_db()
        cursor = db_connection.cursor()
        cursor.execute("SELECT vin_id, ip, latitude, longitude, timestamp FROM client_info")
        data = cursor.fetchall()
        cursor.close()
        db_connection.close()

        if not data:
            return jsonify({'error': 'No data found'})

        return jsonify(data)

    except Exception as e:
        return jsonify({'error': str(e)})

@bp.route('/confirm', methods=['POST'])
def confirm():
    data = request.json
    vin_id = data.get('vin_id')

    if not vin_id:
        return jsonify({'error': 'VIN ID is required'}), 400

    try:
        # Lưu thông tin vào bảng confirm_history
        db_connection = connect_to_db()
        cursor = db_connection.cursor()
        sql = "INSERT INTO confirm_history (vin_id) VALUES (%s)"
        cursor.execute(sql, (vin_id,))
        db_connection.commit()

        # Lấy timestamp để gửi đến client
        cursor.execute("SELECT timestamp FROM confirm_history WHERE vin_id = %s ORDER BY timestamp DESC LIMIT 1", (vin_id,))
        timestamp = cursor.fetchone()[0]
        confirmed_hour = timestamp.hour  # Lấy giờ từ timestamp
        cursor.close()
        db_connection.close()

        # Gửi sự kiện WebSocket để đồng bộ biểu đồ
        socketio.emit(
            'confirm_update',
            {
                'vin_id': vin_id,
                'timestamp': str(timestamp),
                'hour': confirmed_hour
            },
            namespace='/'
        )

        # Gửi thông báo qua MQTT (không thay đổi phần này vì bạn yêu cầu giữ nguyên)
        mqtt_client = current_app.mqtt_client
        message = {"response": f"response from server for client {vin_id}"}
        mqtt_client.publish("response/ecall", json.dumps(message))

        return jsonify({'message': f'Confirmation sent for {vin_id}'})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@bp.route('/confirm-history')
def get_confirm_history():
    try:
        db_connection = connect_to_db()
        cursor = db_connection.cursor()
        cursor.execute("SELECT vin_id, timestamp FROM confirm_history ORDER BY timestamp DESC")
        data = cursor.fetchall()
        cursor.close()
        db_connection.close()
        return jsonify(data)
    except Exception as e:
        return jsonify({'error': str(e)})


@bp.route('/chart-data')
def get_chart_data():
    selected_date = request.args.get('date')
    if not selected_date:
        return jsonify({'error': 'Date is required'}), 400

    try:
        db_connection = connect_to_db()
        cursor = db_connection.cursor()

        # Lấy tổng số eCall trong ngày
        cursor.execute("""
            SELECT HOUR(timestamp) AS hour, COUNT(*) 
            FROM client_info 
            WHERE DATE(timestamp) = %s
            GROUP BY HOUR(timestamp)
            ORDER BY HOUR(timestamp)
        """, (selected_date,))
        total_ecall = cursor.fetchall()

        # Lấy số lượng đã xác nhận cứu hộ trong ngày
        cursor.execute("""
            SELECT HOUR(timestamp) AS hour, COUNT(*) 
            FROM confirm_history 
            WHERE DATE(timestamp) = %s
            GROUP BY HOUR(timestamp)
            ORDER BY HOUR(timestamp)
        """, (selected_date,))
        confirmed = cursor.fetchall()

        cursor.close()
        db_connection.close()

        # Chuyển dữ liệu thành định dạng JSON
        hours = list(range(24))
        total_eCall_dict = {hour: 0 for hour in hours}
        confirmed_dict = {hour: 0 for hour in hours}

        for hour, count in total_ecall:
            total_eCall_dict[hour] = count

        for hour, count in confirmed:
            confirmed_dict[hour] = count

        return jsonify({
            'timestamps': hours,
            'totalECalls': list(total_eCall_dict.values()),
            'confirmed': list(confirmed_dict.values())
        })

    except Exception as e:
        return jsonify({'error': str(e)}), 500
