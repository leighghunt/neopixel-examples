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

int delayval = 5; 
void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  for(int i =0;i<10;++i)
  {

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
   }
    pixels.show();
   delay(10);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
   }
    pixels.show();
    delay(50);
   }

  for(int i =0;i<10;++i)
  {

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
   }
    pixels.show();
   delay(50);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
   }
    pixels.show();
    delay(50);
   }

  for(int i =0;i<10;++i)
  {

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0));
   }
    pixels.show();
   delay(50);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
   }
    pixels.show();
    delay(50);
   }

  for(int i =0;i<10;++i)
  {

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255));
   }
    pixels.show();
   delay(50);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
   }
    pixels.show();
    delay(50);
   }

    // Single pixel
    
    pixels.setPixelColor(0, pixels.Color(100,100,100));
    pixels.show();
    delay(10);

    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
    delay(10);
   
    pixels.setPixelColor(0, pixels.Color(0,255,0));
    pixels.show();
    delay(10);
   
    pixels.setPixelColor(0, pixels.Color(0,0,255));
    pixels.show();
    delay(10);
   
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    pixels.show();
    delay(10);




    // All pixels

   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(100,100,100));
   }
   pixels.show();
   delay(1000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0));
   }
   pixels.show();
   delay(1000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0));
   }
   pixels.show();
   delay(1000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255));
   }
   pixels.show();
   delay(1000);
   
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
   }
   pixels.show();
   delay(1000);
   




  // Rainbow

  int r, g, b;
  r = 0;
  g = 0;
  b = 255;
 
  // fade from blue to violet
  for (r = 0; r < 255; r++) {
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  } 
  // fade from violet to red

  for (b = 255; b > 0; b--) { 
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  } 
  // fade from red to yellow
  for (g = 0; g < 255; g++) { 
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  } 
  // fade from green to teal
  for (b = 0; b < 255; b++) { 
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  } 
  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r, g, b));
   } 
    pixels.show();
    delay(delayval);
  }
}

