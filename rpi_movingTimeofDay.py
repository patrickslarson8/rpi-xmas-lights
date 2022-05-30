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
