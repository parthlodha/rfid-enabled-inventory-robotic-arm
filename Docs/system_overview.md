# System Overview

The project implements a semi-automated robotic arm system designed for identified object handling using RFID technology.

Manual control is provided through a standard gamepad interface, allowing intuitive operation without complex training. Object identification is achieved using RFID tags, enabling digital traceability during physical handling tasks.

---

## Core Subsystems

- **Human Interface**  
  A gamepad provides real-time control inputs for robotic arm movement and gripping actions.

- **Host Processing Layer**  
  A Python-based application translates raw gamepad signals into structured motion commands.

- **Embedded Control Layer**  
  A microcontroller receives motion commands, applies smoothing and safety limits, and coordinates peripheral modules.

- **Actuation Layer (Servo Driver)**  
  A 16-channel PWM servo driver (e.g., PCA9685) generates precise PWM signals for all robotic joints, reducing microcontroller load and improving signal stability.

- **Sensing Layer**  
  An RFID reader detects tagged objects and generates identification events.


## Design Philosophy

The system prioritizes modularity, clarity, and expandability.  
Each subsystem performs a clearly defined role, enabling future enhancements without architectural redesign.
