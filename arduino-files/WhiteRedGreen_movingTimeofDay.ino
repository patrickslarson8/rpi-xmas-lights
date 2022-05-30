// This code outputs a light pattern of Red, Green, and White, and moves that pattern
// one bulb down the strip. When it receives unicode "GO" over the serial 
// connection it will begin output. Anything else will stop the output.

#include <FastLED.h>

#define LED_PIN     6

// Information about the LED strip itself
#define NUM_LEDS    150
#define CHIPSET     WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define BRIGHTNESS      52 //default was 128

// I had a section of lights that overlapped with another section due to the configuration
// of my roof. Setting these values turned those lights off so you could not seem them at night
#define LED_DEAD_START  109
#define LED_DEAD_STOP   123


#define TEMPERATURE     UncorrectedTemperature

// A yellow-ish color intended to mimic the glow of incandescent bulbs (it does not)
#define MEGAN_WHITE     0xc9b96f

int DELAY_TIME = 2000;
String data = "Go";

int counter = 0;
int offset = 0;

void loop() {
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    Serial.println(data);
    }
  if (data == "Go"){
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
        leds[i] = CRGB(MEGAN_WHITE);
        counter = 0;
      }
    }
    for (int i =0; i < NUM_LEDS; i++) {
      if ((i >= LED_DEAD_START) && (i <= LED_DEAD_STOP)) {
        leds[i] = CRGB::Black;
      }
    }
    FastLED.show();
    delay(2000);
    for (int i = 0; i <NUM_LEDS; i++) {
      if (counter == 0) {
        leds[i] = CRGB(MEGAN_WHITE);
        counter++;
      }
      else if (counter == 1) {
        leds[i] = CRGB::Red;
        counter++;
      }
      else {
        leds[i] = CRGB::Green;
        counter = 0;
      }
    }
    for (int i =0; i < NUM_LEDS; i++) {
      if ((i >= LED_DEAD_START) && (i <= LED_DEAD_STOP)) {
        leds[i] = CRGB::Black;
      }
    }
    FastLED.show();
    delay(2000);
    for (int i = 0; i <NUM_LEDS; i++) {
      if (counter == 0) {
        leds[i] = CRGB::Green;
        counter++;
      }
      else if (counter == 1) {
        leds[i] = CRGB(MEGAN_WHITE);
        counter++;
      }
      else {
        leds[i] = CRGB::Red;
        counter = 0;
      }
    }
    for (int i =0; i < NUM_LEDS; i++) {
      if ((i >= LED_DEAD_START) && (i <= LED_DEAD_STOP)) {
        leds[i] = CRGB::Black;
      }
    }
    FastLED.show();
    delay(2000);
  }
  else {
    for (int i=0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(2000)
  }
}

void setup() {
  delay( 3000 ); // power-up safety delay
  // It's important to set the color correction for your LED strip here,
  // so that colors can be more accurately rendered through the 'temperature' profiles
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
  Serial.begin(9600);
}
