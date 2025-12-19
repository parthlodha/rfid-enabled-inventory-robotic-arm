# PC–Microcontroller Communication Protocol

The system uses serial communication between a host PC and the microcontroller.

The PC reads gamepad inputs and sends formatted control packets to the Arduino, which interprets and executes them in real time.

---

## Packet Format

<BASE,LINK1,LINK2,GRIP>

Example:
<90,120,45,1>

- BASE  → Base rotation angle (0–180)
- LINK1 → Shoulder joint angle
- LINK2 → Elbow joint angle
- GRIP  → Gripper state (0 = open, 1 = close)

Packets are newline-terminated and transmitted at 115200 baud.

## RFID Event Messages

RFID detections are transmitted asynchronously using the format:

<RFID,tag_id>

Example:
<RFID,a3f29c11>

These messages are intended for future inventory logging and system integration.
