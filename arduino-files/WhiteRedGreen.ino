# Creates a simple fixed output lights to simulate traditional light strands

#include <FastLED.h>

#define LED_PIN     6

// Information about the LED strip itself
#define NUM_LEDS    150
#define CHIPSET     WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define BRIGHTNESS      52 //default was 128
#define LED_DEAD_START  109
#define LED_DEAD_STOP   123
#define DELAY_TIME      1000
#define TEMPERATURE     Candle

int counter = 0;
int offset = 0;
void loop()
{
  for (int i = 0; i <NUM_LEDS; i++) {
    if (counter == 0) {
      leds[i] = CRGB::Red;
      counter++;
    }
    else if (counter == 1) {
      leds[i] = CRGB::Green;
      counter++;
    }
    else {
      leds[i] = CRGB::White;
      counter = 0;
    }
  }
  for (int i =0; i < NUM_LEDS; i++) {
    if ((i >= LED_DEAD_START) && (i <= LED_DEAD_STOP)) {
      leds[i] = CRGB::Black;
    }
  }
  FastLED.show();
  delay(DELAY_TIME);
  FastLED.clear();
  delay(DELAY_TIME);
}

void setup() {
  delay( 3000 ); // power-up safety delay
  // It's important to set the color correction for your LED strip here,
  // so that colors can be more accurately rendered through the 'temperature' profiles
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );

}
