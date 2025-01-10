from flask import Flask
from app import create_app, socketio
from app.mqtt_handler import on_message
import paho.mqtt.client as mqtt

# Tạo ứng dụng Flask
app = create_app()

# Cấu hình MQTT
mqtt_client = mqtt.Client()
mqtt_client.on_message = on_message
mqtt_client.connect("localhost", 1883, 60)
mqtt_client.subscribe("ecall/response")

# Lưu trữ mqtt_client trong app context
app.mqtt_client = mqtt_client

# Chạy MQTT trong một luồng riêng
import threading
mqtt_thread = threading.Thread(target=mqtt_client.loop_forever)
mqtt_thread.start()

if __name__ == '__main__':
    print("Starting Flask-SocketIO server...")
    socketio.run(app, host='0.0.0.0', port=5000)
