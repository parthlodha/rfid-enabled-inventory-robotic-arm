# Release v1.0.0

This release marks the first stable version of the RFID-based robotic arm system.

The focus of Version 1.0 is on clean system architecture, reliable manual control, and extensibility for future automation. The system is implemented using a human-in-the-loop control approach rather than full autonomy.

---

## Key Features

- Gamepad-based manual control via host PC
- Python application for input processing and command generation
- Serial communication between host and microcontroller
- Smooth, acceleration-limited joint motion
- 16-channel PWM servo driver (PCA9685) for stable actuation
- RFID-based object identification using MFRC522
- Structured RFID event messages over serial
- Modular firmware and software design

---

## System Architecture Summary

- Host PC handles user input and command formatting
- Microcontroller coordinates motion and sensing
- Dedicated servo driver generates PWM signals
- RFID operates asynchronously alongside motion control

---

## Known Limitations

- System operates in supervised (manual) mode
- Persistent inventory logging is not implemented
- Object grasping depends on operator skill
- No vision-based feedback in current version

These limitations are intentional to maintain reliability and simplicity in the initial prototype.

---

## Future Roadmap

- Inventory logging and database integration
- Assisted and semi-autonomous control modes
- Vision-assisted grasping and alignment
- Wireless host-to-controller communication
- Scalability to higher DOF robotic arms

---

## Author

Parth Lodha  
Engineering Student – Robotics & Embedded Systems

This release represents a stable foundation for further research and development.
