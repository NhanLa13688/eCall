from flask import Flask
from flask_socketio import SocketIO
import eventlet

eventlet.monkey_patch()

# Khởi tạo Flask-SocketIO
socketio = SocketIO(cors_allowed_origins="*", async_mode="eventlet")

def create_app():
    app = Flask(__name__)
    app.config.from_pyfile('../config.py')

    # Gắn kết socketio với app
    socketio.init_app(app)

    # Đăng ký blueprint
    from app.routes import bp as routes_bp
    app.register_blueprint(routes_bp)

    return app
