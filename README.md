# 🚗 eCall System for Vehicles

This project demonstrates the implementation of an **eCall (Emergency Call) system** for vehicles, designed to enhance safety by automatically notifying emergency services in case of an accident. The system complies with European standards for eCall and can be adapted for other regions.

---

## 🌟 Features

- **Automatic Incident Detection**: Detects collisions or accidents using sensors (e.g., accelerometer, gyroscope).
- **Emergency Call Activation**: Automatically initiates a voice call to emergency services with vehicle location.
- **Manual Trigger**: Allows users to manually activate the emergency call system.
- **GPS Integration**: Sends precise vehicle location data to emergency responders.
- **CAN Communication**: Integrates with the vehicle's CAN bus for real-time data acquisition.
- **Simulated Environment**: Supports testing in a simulated environment using tools like CANoe or Python-based simulations.

---

## 🛠️ Architecture

### Components
1. **Crash Detection Module**:
   - Monitors sensor data (accelerometer, gyroscope) for thresholds indicating a collision.
2. **Communication Module**:
   - Initiates a voice call or sends a data message to emergency services.
3. **GPS Module**:
   - Retrieves the vehicle's real-time location using a GPS receiver.
4. **CAN Integration**:
   - Interfaces with the vehicle's CAN bus to retrieve system status and diagnostics.

### Flow Diagram
```text
Sensor Data ---> Crash Detection ---> Emergency Trigger ---> Communication (Voice/Data)
                                   |
                              GPS Location
                                   |
                           CAN Data Integration
