# Working Principle

The RFID-based robotic arm operates using a human-in-the-loop control architecture, combining manual precision with digital traceability.

The system is divided into two primary layers: a host control layer and an embedded execution layer.

---

## Step-by-Step Operation

1. A gamepad connected to a host computer captures user inputs such as joystick movement and button presses.
2. A Python script processes these inputs, applies deadzone and sensitivity corrections, and converts them into target joint angles.
3. The processed control data is transmitted to the microcontroller via serial communication using a structured packet format.
4. The microcontroller parses incoming packets and updates target positions for each joint.
5. Target joint positions are converted into PWM commands and transmitted to the 16-channel servo driver over the I²C bus.
6. The servo driver generates accurate PWM signals to control each joint smoothly and consistently.
7. When an RFID-tagged object is brought near the reader, the tag ID is detected independently of motion control.
8. RFID events are transmitted back to the host system as structured serial messages.

This architecture ensures responsive manual control while maintaining extensibility for future automation and logging features.
