# This code is used to turn the arduino RGB output on or off at
# a specified time of day. The raspberry pi sends a single unicode
# letter which the arduino then interprets to switch between
# a pre-programmed string or all black output

#!/usr/bin/env python3
import serial
import time
import datetime

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()

    while True:
        if datetime.datetime.now().hour >=16:
            ser.write(b"Go\n")
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            time.sleep(60)
        else:
            ser.write(b"Stop\n")
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            time.sleep(60)
