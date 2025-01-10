import json
from app import socketio
from app.database import connect_to_db

client_info = {}

def on_message(client, userdata, msg):
    global client_info
    try:
        # Parse dữ liệu từ MQTT
        data = json.loads(msg.payload)
        client_info = {
            "vin_id": data.get("vin_id"),
            "ip": data.get("ip"),
            "latitude": data.get("latitude"),
            "longitude": data.get("longitude")
        }
        print(f"Received MQTT message: {client_info}")

        # Lưu dữ liệu vào MySQL
        db_connection = connect_to_db()
        cursor = db_connection.cursor()
        sql = """
            INSERT INTO client_info (vin_id, ip, latitude, longitude)
            VALUES (%s, %s, %s, %s)
            ON DUPLICATE KEY UPDATE
                latitude = VALUES(latitude),
                longitude = VALUES(longitude),
                timestamp = CURRENT_TIMESTAMP;
        """
        cursor.execute(sql, (client_info['vin_id'], client_info['ip'], client_info['latitude'], client_info['longitude']))
        db_connection.commit()
        cursor.close()
        db_connection.close()

        # Phát sự kiện qua WebSocket
        socketio.emit('update', client_info)

    except Exception as e:
        print(f"Error processing MQTT message: {e}")
