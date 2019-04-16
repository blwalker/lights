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



#define NUM_LEDS 50
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

int toggle = 0;
int r = 0;
int g = 0;
int b = 0;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  //  FastLED.addLeds<NEOPIXEL, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  for (int st = 0; st < 255; st++)  {

    if (toggle) {
      r = st;
      g = 255 - st;
    }
    else {
      r = 255 - st;
      g = st;
    }

    for (int x = 0; x < NUM_LEDS; x++) {
      if (x % 2 == 0)
        leds[x] = CRGB(r, g, b);
      else
        leds[x] = CRGB(g, r, b);
    }

    FastLED.show();
    delay(50);
  }

  toggle = !toggle;
}
