import struct
import time

import pyautogui
import sock as sock
import win32api, win32con
import serial as com
import socket


hw, hh = 1920 // 2, 1080 // 2
dd = 0.1  # joystick dead zone
speed = 3  # xplane camera speed

cx, cy, d = hw, hh, 0


hostname = socket.gethostname()
UDP_IP = socket.gethostbyname(hostname)
print(UDP_IP)
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.settimeout(1)
sock.bind((UDP_IP, UDP_PORT))

while True:
    try:
        data, addr = sock.recvfrom(41)
        win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN, cx, cy, 0, 0)
        rx = -struct.unpack('f', data[9:13])[0]
        speed_mul = abs(rx) * 2

        if rx > dd:  # turn
            d = min(d + speed * speed_mul, hw)
        elif rx < -dd:
            d = max(d - speed * speed_mul, -hw)
        else:
            pass
            #d = d / 1.05


        win32api.SetCursorPos((int(cx + d), int(cy)))
    except Exception as e:
        time.sleep(1)
        print(e)