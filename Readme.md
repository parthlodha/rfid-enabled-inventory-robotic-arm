This repository documents an academic prototype developed and validated as part of coursework and personal experimentation.

# RFID Based Robotic Arm for Medicine Inventory Management

This project presents an RFID-enabled robotic arm system designed to assist in medicine inventory management.  
The robotic arm is manually controlled using a gamepad, while RFID technology is used to identify and log medicines during pick-and-place operations.

The system demonstrates the integration of robotics, embedded systems, and inventory automation—focused on reliability, simplicity, and real-world applicability.

---

## Key Features

- Gamepad-controlled multi-DOF robotic arm
- RFID-based medicine identification
- Real-time inventory logging
- Manual pick-and-place with digital traceability
- Modular hardware and firmware design

---

## System Overview

The operator controls the robotic arm using a gamepad interface.  
When a medicine container equipped with an RFID tag is picked, the RFID reader scans the tag and sends the data to the controller.  
This information is logged for inventory tracking and verification.

The design allows human supervision while eliminating manual record-keeping errors.

---

## Hardware Components

- Microcontroller (Arduino / ESP32)
- Multi-DOF servo-based robotic arm
- RFID reader and tags
- Gamepad controller
- Power supply and servo driver module
- Mechanical frame and gripper

---

## Software & Firmware

- Embedded C/C++ for robotic arm control
- Gamepad input processing
- RFID tag reading and validation
- RFID data acquisition is currently implemented.
- Inventory logging is architected and documented, with planned extensions in future versions
- Serial / local storage based data handling

---

## Applications

Although demonstrated using a medicine handling scenario, the system architecture is generic and can be adapted to multiple domains where identified object handling and traceability are required.

Potential applications include:

- **Pharmaceutical & Medical Stores**  
  Assisted inventory handling, medicine identification, and manual stock verification.

- **Warehouse & Inventory Management**  
  RFID-based item identification during pick-and-place operations in small-scale warehouses.

- **Laboratory Sample Handling**  
  Controlled movement and identification of tagged samples in academic or research labs.

- **Manufacturing & Assembly Lines**  
  Semi-automated part handling with RFID-based component verification.

- **Library & Document Management Systems**  
  Handling and tracking of RFID-tagged books or files.

- **Educational Robotics & Training**  
  Demonstration platform for robotics, embedded systems, and human–machine interaction.

- **Retail Stock Assistance**  
  Back-end stock organization and tagged item handling under human supervision.

The modular design allows the same control and identification framework to be reused across domains with minimal hardware or software modification.


## Repository Structure

- `hardware/` – circuit diagrams, block diagrams, mechanical models  
- `firmware/` – microcontroller code for arm, RFID, and gamepad  
- `software/` – inventory handling and data logs  
- `docs/` – detailed documentation  
- `demo/` – images and video references  

---

## Demo & Validation

A video demonstrating the motion-control testing phase of the robotic arm is provided.

The RFID module was integrated and functionally verified during development through serial communication and code-level validation. At the time of final documentation, the robotic arm had been dismantled as part of the prototyping cycle; therefore, a consolidated hardware demo video including RFID operation is not available.

The current repository focuses on presenting the final system architecture, firmware implementation, and validated control logic.


## Future Enhancements

- Autonomous picking using predefined slots
- Database-linked inventory system
- Web dashboard for stock monitoring
- AI-based medicine classification
- Vision-assisted grasping

---

## Author

Parth Lodha  
Engineering Student – Robotics & Embedded Systems

This project is part of my academic and portfolio work, focused on practical automation systems.
