// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      32

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 200; 
void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

    pixels.setPixelColor(0, pixels.Color(100,100,100));
    pixels.show();
    delay(5000);

    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(0, pixels.Color(0,255,0));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(0, pixels.Color(0,0,255));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    pixels.show();
    delay(5000);

    pixels.setPixelColor(1, pixels.Color(100,100,100));
    pixels.show();
    delay(5000);

    pixels.setPixelColor(2, pixels.Color(255,0,0));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(3, pixels.Color(0,255,0));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(4, pixels.Color(0,0,255));
    pixels.show();
    delay(5000);
   
    pixels.setPixelColor(5, pixels.Color(255,255,255));
    pixels.show();
    delay(5000);

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(100,100,100));
   }
   pixels.show();
   delay(5000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0));
   }
   pixels.show();
   delay(5000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0));
   }
   pixels.show();
   delay(5000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255));
   }
   pixels.show();
   delay(5000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
   }
   pixels.show();
   delay(5000);
   
      /*
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(i, i, i));
    pixels.show();
    delay(delayval);
   }
   */
}

