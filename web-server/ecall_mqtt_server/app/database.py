import mysql.connector

def connect_to_db():
    conn = mysql.connector.connect(
        host="localhost",
        user="root",
        password="1q@w3e4R",
        database="ecall_data",
    )
     # Đặt múi giờ cho kết nối
    cursor = conn.cursor()
    cursor.execute("SET time_zone = '+07:00';")
    cursor.close()
    return conn

def save_client_data(client_info):
    conn = connect_to_db()
    cursor = conn.cursor()
    sql = """
        INSERT INTO client_info (vin_id, ip, latitude, longitude)
        VALUES (%s, %s, %s, %s)
        ON DUPLICATE KEY UPDATE
            latitude = VALUES(latitude),
            longitude = VALUES(longitude),
            timestamp = CURRENT_TIMESTAMP;
    """
    cursor.execute(sql, (client_info['vin_id'], client_info['ip'], client_info['latitude'], client_info['longitude']))
    conn.commit()
    cursor.close()
    conn.close()

def get_client_data():
    conn = connect_to_db()
    cursor = conn.cursor()
    cursor.execute("SELECT vin_id, ip, latitude, longitude, timestamp FROM client_info")
    data = cursor.fetchall()
    cursor.close()
    conn.close()
    return data
