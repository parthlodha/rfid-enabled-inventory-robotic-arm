import pygame
import serial
import time

SERIAL_PORT = "COM5"      # Update as required
BAUD_RATE = 115200

DEADZONE = 0.08
SENSITIVITY = 0.9

pygame.init()
pygame.joystick.init()

if pygame.joystick.get_count() == 0:
    raise RuntimeError("No gamepad detected")

joystick = pygame.joystick.Joystick(0)
joystick.init()

ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)

def process_axis(val, out_min, out_max):
    if abs(val) < DEADZONE:
        val = 0.0
    val *= SENSITIVITY
    return int((val + 1) * (out_max - out_min) / 2 + out_min)


print("Gamepad control active")

while True:
    pygame.event.pump()

    base  = process_axis(joystick.get_axis(0), 0, 180)
    link1 = process_axis(joystick.get_axis(1), 30, 150)
    link2 = process_axis(joystick.get_axis(3), 30, 150)

    grip = 1 if joystick.get_button(0) else 0

    packet = f"<{base},{link1},{link2},{grip}>\n"
    ser.write(packet.encode())

    time.sleep(0.02)
