# RFID-Based Robotic Arm with Gamepad Control

## Abstract
This report presents the design and implementation of an RFID-based robotic arm system controlled using a gamepad. The system follows a human-in-the-loop architecture, where a host computer processes gamepad inputs and transmits structured motion commands to a microcontroller. A 16-channel PWM servo driver is used for stable and scalable joint actuation, while an RFID reader provides object identification during handling operations. The project focuses on system architecture, reliable control, and extensibility rather than full inventory automation, making it suitable for semi-automated handling applications across multiple domains.

---

## 1. Introduction

### 1.1 Background
Radio Frequency Identification (RFID) is widely used for object identification and tracking in logistics, retail, and industrial environments. When combined with robotic systems, RFID enables traceability during physical manipulation tasks. Robotic arms provide precise, repeatable motion, making them suitable platforms for sensor-assisted object handling.

### 1.2 Motivation
Conventional RFID systems rely on static readers or manual scanning, which limits flexibility and increases dependence on human effort. Introducing a robotic arm allows RFID scanning to be performed at different orientations and positions while retaining human supervision for safety and control.

### 1.3 Objectives
The objectives of this project are:
- To design a multi-joint robotic arm system with integrated RFID sensing.
- To implement intuitive manual control using a standard gamepad interface.
- To achieve smooth and reliable joint motion using a dedicated servo driver.
- To establish a clean communication architecture that supports future automation and logging.

---

## 2. System Architecture

The system is divided into clearly defined functional layers:

- **Human Interface Layer**: A gamepad connected to a host computer captures user inputs.
- **Host Processing Layer**: A Python application processes raw gamepad data, applies deadzone and sensitivity correction, and generates structured motion commands.
- **Embedded Control Layer**: A microcontroller receives serial commands, manages motion targets, and coordinates peripheral devices.
- **Actuation Layer**: A 16-channel PWM servo driver (PCA9685) generates precise PWM signals for all robotic joints via the I²C interface.
- **Sensing Layer**: An RFID reader detects tagged objects and transmits identification events.

This layered approach improves modularity and simplifies debugging and future expansion.

---

## 3. Working Principle

1. The operator manipulates the gamepad to control joint motion and gripping actions.
2. The host-side Python program reads the gamepad inputs and maps them to target joint angles.
3. Control commands are sent to the microcontroller over serial communication using a predefined packet format.
4. The microcontroller parses incoming packets and updates target positions for each joint.
5. Joint motion is executed gradually using acceleration-limited control to ensure smooth movement.
6. The servo driver receives angle-based PWM commands over I²C and drives the connected servos.
7. When an RFID-tagged object is detected, the RFID reader generates an identification event.
8. RFID events are transmitted back to the host system as structured serial messages.

The control loop is non-blocking, allowing motion control and sensing to operate concurrently.

---

## 4. Hardware Configuration

### 4.1 Major Components
- Microcontroller (Arduino-class)
- 16-channel PWM servo driver (PCA9685)
- Multi-degree-of-freedom robotic arm with servo motors
- MFRC522 RFID reader and passive RFID tags
- External power supply for servos
- USB-connected gamepad

### 4.2 Actuation Strategy
Using a dedicated servo driver offloads PWM generation from the microcontroller, reduces timing jitter, and allows the system to scale to additional joints without architectural changes.

---

## 5. Software and Firmware Design

### 5.1 Host-Side Software
The Python-based control program is responsible for:
- Reading gamepad axes and buttons
- Applying deadzone and sensitivity correction
- Formatting and transmitting control packets

### 5.2 Embedded Firmware
The microcontroller firmware handles:
- Serial packet parsing
- Target-based servo control with smoothing
- I²C communication with the servo driver
- RFID detection and event generation

The firmware is designed to be readable, modular, and easily extendable.

---

### 6. Block diagram 




















## 7. Applications

Although demonstrated using RFID-tagged objects, the system architecture is domain-agnostic and can be adapted for:
- Inventory and warehouse assistance
- Laboratory sample handling
- Manufacturing and assembly verification
- Library and document management
- Educational robotics and training

---

## 8. Limitations

- The current system operates in a manual, supervised mode.
- Persistent inventory logging is not implemented in the present version.
- Object placement and grasping rely on operator skill rather than autonomous planning.

These limitations are intentional to maintain system reliability and simplicity in the initial version.

---

## 9. Future Scope

Planned enhancements include:
- Persistent inventory logging using CSV, SD card, or database systems
- PC-side parsing of RFID events for stock management
- Mode-based operation (manual and assisted)
- Vision-assisted alignment and grasping
- Wireless communication between host and controller

---

## 10. Conclusion

This project demonstrates a reliable and extensible RFID-based robotic arm system using a human-in-the-loop control strategy. By combining gamepad control, structured communication, a dedicated servo driver, and RFID sensing, the system establishes a strong foundation for semi-automated object handling. The modular architecture allows future expansion toward greater autonomy and integration without redesigning the core system.

---

## Author

Parth Lodha , 2024
Roll No: 16010323022  
Minor in Robotics & AI

