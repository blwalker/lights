#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <cpp_compat.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <lib8tion.h>
#include <noise.h>
#include <pixelset.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>



#define LED_COUNT 50
#define DATA_PIN 6
#define MAXVAL 255
#define WAITMS 20
#define SHOWHOLD 750

// Define the array of leds
CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, LED_COUNT);
}

void change(int r, int g, int b) {
  for (int x = 0; x < LED_COUNT; x++) {
    leds[x] = CRGB(r, g, b);
  }

  delay(WAITMS);
  FastLED.show();
}

void loop() {
  // blue to white
  for (int x = 0; x <= MAXVAL; x++) {
    int r = x;
    int g = x;
    int b = MAXVAL;

    change(r, g, b);
  }

  delay(SHOWHOLD);

  // white to teal
  for (int x = MAXVAL; x >= 0; x--) {
    int r = x;
    int g = MAXVAL;
    int b = MAXVAL;

    change(r, g, b);
  }

  delay(SHOWHOLD);

  // teal to purple
  for (int rx = 0, gx = MAXVAL; rx <= MAXVAL; rx++, gx--) {
    int r = rx;
    int g = gx;
    int b = MAXVAL;

    change (r, g, b);
  }

  delay(SHOWHOLD);

  // purple to blue
  for (int x = MAXVAL; x >= 0; x--) {
    int r = x;
    int g = 0;
    int b = MAXVAL;

    change(r, g, b);
  }

  delay(SHOWHOLD);
} //end main loop
