import board
import neopixel
pixels = neopixel.NeoPixel(board.D18, 30)

while True:
    pixels[0] =(255, 0, 0)
    pixels[1] = (0,255,0)