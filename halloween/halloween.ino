/*
MIT License

Copyright (c) 2018 Brent L. Walker

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <FastLED.h>

const uint8_t STEPS = 64;
const uint8_t COUNT = 50;

const uint16_t BIG_DELAY = 5000;
const uint8_t SATURATION = 224;
const uint8_t BRIGHTNESS = 164;

const uint8_t ORANGE = 24;
const uint8_t GREEN = 96;
const uint8_t PURPLE = 192;

CRGB leds[COUNT];

void setup()
{
  FastLED.addLeds<WS2812B, 6>(leds, COUNT);
}

void loop()
{
  static uint8_t mode = 0;
  static double diff = 0.0;

  for (uint8_t i = 0; i < COUNT; i++)
  {
    switch ((mode + i) % 3)
    {
      case 0:
        leds[i] = CHSV(ORANGE, SATURATION, BRIGHTNESS);
        break;

      case 1:
        leds[i] = CHSV(GREEN, SATURATION, BRIGHTNESS);
        break;

      case 2:
        leds[i] = CHSV(PURPLE, SATURATION, BRIGHTNESS);
        break;
    }
  }

  FastLED.show();
  delay(BIG_DELAY);

  for (uint8_t step = 0; step < STEPS; step++)
  {
    for (uint8_t i = 0; i < COUNT; i++)
    {
      switch ((mode + i) % 3)
      {
        case 0:
          diff = (GREEN - ORANGE) / static_cast<double>(STEPS);
          leds[i] = CHSV((diff * step) + ORANGE, SATURATION, BRIGHTNESS);
          break;

        case 1:
          diff = (PURPLE - GREEN) / static_cast<double>(STEPS);
          leds[i] = CHSV((diff * step) + GREEN, SATURATION, BRIGHTNESS);
          break;

        case 2:
          diff = (255 - PURPLE + ORANGE) / static_cast<double>(STEPS);
          leds[i] = CHSV((diff * step) + PURPLE, SATURATION, BRIGHTNESS);
          break;
      }
    }

    FastLED.show();
    delay(25);
  }

  mode++;
}

