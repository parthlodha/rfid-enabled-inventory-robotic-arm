# Pin Configuration

This document describes the final pin connections used in the RFID-based robotic arm system.

---

## Microcontroller ↔ Servo Driver (PCA9685)

The system uses a 16-channel PWM servo driver for stable and scalable actuation.

| Signal | Microcontroller Pin |
|------|---------------------|
| SDA  | A4                  |
| SCL  | A5                  |
| VCC  | 5V                  |
| GND  | GND                 |
| V+   | external 5v         |
---

## Servo Channel Mapping (PCA9685)

| Servo Function | Driver Channel |
|----------------|----------------|
| Base Rotation  | CH0            |
| Link 1         | CH1            |
| Link 2         | CH2            |

Servo power is supplied externally through the servo driver power terminals.

---

## RFID Module (MFRC522 – SPI Interface)

| RFID Signal | Microcontroller Pin |
|------------|---------------------|
| SDA / SS   | D10                 |
| RST        | D8                  |
| MOSI       | D11                 |
| MISO       | D12                 |
| SCK        | D13                 |
| VCC        | 3.3V                |
| GND        | GND                 |

---

## Notes

- Common ground must be maintained between all modules.
- Servo power should not be drawn from the microcontroller.
- Pin assignments may be updated based on hardware revisions.
