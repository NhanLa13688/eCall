# 🚗 eCall System for Vehicles

This repository showcases the development of an **eCall system** designed for vehicles to enhance safety and emergency response. The system can automatically detect accidents and notify emergency services, providing critical information such as vehicle location and crash details.

---

## 🌟 Features

- **Automatic Incident Detection**: Identifies accidents using onboard sensors (e.g., accelerometer, gyroscope).
- **Emergency Call Activation**: Automatically initiates a voice or data call to emergency services.
- **Manual Override**: Allows users to manually trigger emergency calls.
- **GPS Integration**: Sends accurate vehicle location data to responders.
- **CAN Bus Support**: Interfaces with the vehicle’s CAN bus for real-time status updates.
- **Simulation Support**: Compatible with tools like CANoe for testing in simulated environments.

---

## 🛠️ System Overview

### Components
1. **Crash Detection Module**:
   - Monitors sensor inputs to identify collision events.
2. **Communication Module**:
   - Initiates emergency communication with preconfigured contacts or services.
3. **Location Module**:
   - Provides real-time GPS data for emergency services.
4. **CAN Integration**:
   - Interfaces with the vehicle’s onboard systems for diagnostics and data sharing.

### Workflow
```plaintext
1. Detect Crash --> 2. Gather GPS Data --> 3. Notify Emergency Services --> 4. Log and Monitor
```

---

## 🧰 Tools and Technologies

- **Programming Languages**: Python, C++
- **Hardware**: Raspberry Pi, GPS Module, Accelerometer
- **Simulation**: CANoe (for CAN bus testing)
- **Standards**:
  - EN 16072: eCall high-level application requirements
  - EN 15722: eCall minimum set of data

---

## 🚀 Getting Started

### Prerequisites
1. Install Python 3.x or a compatible C++ compiler.
2. Set up CANoe or a similar simulation tool for CAN testing.
3. Connect a GPS module and accelerometer to your development board.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/ecall-system.git
   cd ecall-system
   ```
2. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```
3. Configure the hardware setup as per the [documentation](docs/HardwareSetup.md).

---

## 📊 Demo

- **Crash Simulation**:
  - Simulate crash scenarios to trigger the eCall system.
  - Observe the automatic call initiation and GPS data transmission.
- **CAN Bus Integration**:
  - Test real-time data exchange using CANoe or other tools.

---

## 📂 Project Structure

```plaintext
ecall-system/
│
├── src/                 # Source code
├── docs/                # Documentation and diagrams
├── tests/               # Test cases
├── requirements.txt     # Python dependencies
└── README.md            # Project overview
```

---

## 📜 Documentation

Detailed setup and usage instructions are available in the [docs/](docs/) directory.

---

## 🤝 Contribution

Contributions are welcome! Please see the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines.

---

## 📧 Contact

For inquiries or collaboration, please reach out at **[lathanhnhan20797@gmail.com](mailto:lathanhnhan20797@gmail.com)**.

---

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more details.


