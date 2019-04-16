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
bool toggle = false;

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop()
{
  for (int x = 0; x < NUM_LEDS; x++)
  {
    switch (x % 2)
    {
      case 0:
        if (toggle)
          leds[x] = CRGB(0, 128, 0);
        else
          leds[x] = CRGB(92, 128, 0);
        break;

      case 1:
        if (toggle)
          leds[x] = CRGB(92, 128, 0);
        else
          leds[x] = CRGB(0, 128, 0);
        break;
    }
  }

  FastLED.show();
  delay(2000);
  toggle = !toggle;
}
