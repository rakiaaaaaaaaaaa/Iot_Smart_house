🏠 Home Automation using Arduino and Blynk (Simulation Project)
This project is a simulated Home Automation System built as part of an academic internship focused on Internet of Things (IoT) and Embedded Systems. It demonstrates the remote control and monitoring of home devices using Arduino, the Blynk IoT app, and the Picsimlab simulator.

📌 Project Overview
The system simulates key smart home functionalities:

💡 Garden Lights Control using LDR sensor values

🌡️ Temperature Monitoring and Control with heater/cooler logic

🚰 Water Tank Management (inlet and outlet valve control)

All devices are simulated, making it suitable for learning and experimentation without physical hardware.

🔧 Tools & Technologies
Arduino IDE – for microcontroller programming (C/C++)

Picsimlab – simulates Arduino hardware and peripherals

Blynk App – mobile IoT platform for remote interaction

Null Modem Emulator – for serial communication emulation

📲 Key Features
Remote Control via Blynk: Includes buttons, gauges, and terminal widgets

Simulated Sensors and Actuators: LDR, LM35, valves, LEDs

CLCD & Serial Communication: For real-time feedback and control logic

Threshold-Based Automation:

Auto shutdown heater if temperature > 35°C

Auto close inlet valve when water tank is full
![architecture1](https://github.com/user-attachments/assets/cd1681e0-3c11-4bde-9fca-b62331916991)
![architecture](https://github.com/user-attachments/assets/18d30b38-88ff-4bab-a887-9454432fbbcf)
🖼️ User Interface (Blynk)
Tab 1: Control water valves, monitor tank level, receive alerts

Tab 2: Control temperature devices, monitor current temperature
![app2](https://github.com/user-attachments/assets/bd37aaf6-0386-43c4-adb8-564c83c72c3a)
![app1](https://github.com/user-attachments/assets/0f6a7dd3-c18e-470a-8fdb-b9b1282173c3)


📁 Repository Structure
markdown
Copier
Modifier
├── Arduino_Code/
│   └── home_automation.ino
├── README.md
└── Report/
    └── IoT_Internship_Report.pdf
🧠 Learning Outcomes
Practical understanding of embedded systems and IoT architecture

Integration of virtual sensors and actuators using simulation tools

Application of C/C++ in hardware-level programming

Mobile IoT dashboard design using Blynk

🚀 Future Enhancements
Add real hardware support for deployment

Expand device automation (e.g., smart curtains, door locks)

Implement data logging and analysis in the cloud

