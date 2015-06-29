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

int delayval = 5; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
/*
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
*/
// End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.


   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(10, 10, 10));
   }
    pixels.show();
    delay(100);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(255, 0, 00));
   }
    pixels.show();
    delay(100);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
   }
    pixels.show();
    delay(100);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
   }
    pixels.show();
    delay(100);
   for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
   }
    pixels.show();
    delay(200);
}

void loop() {
  
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
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  /*
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(i + 8, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.setPixelColor(i + 7, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(150,0,0)); // Moderately bright green color.
    pixels.setPixelColor(i + 8, pixels.Color(150,0,0)); // Moderately bright green color.
    pixels.setPixelColor(i + 7, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
   for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,150)); // Moderately bright green color.
    pixels.setPixelColor(i + 8, pixels.Color(0,0,150)); // Moderately bright green color.
    pixels.setPixelColor(i + 7, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }

  for(int l=0;l<255;l++){
     for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(l,l,l)); // Moderately bright green color.

   }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(10); // Delay for a period of time (in milliseconds).
  }


  for(int l=0;l<255;l++){
     for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(l,l,l)); // Moderately bright green color.

   }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(10); // Delay for a period of time (in milliseconds).
  }

   for(int l=255;l>=0;l--){
     for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(l,l,l)); // Moderately bright green color.

   }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(100); // Delay for a period of time (in milliseconds).
  }

  for(int i = 0; i < 10; ++i)
  {
    setAllPixels(0,0,0);
    delay(100); // Delay for a period of time (in milliseconds).
  
    setAllPixels(255,255,255);
    delay(10); // Delay for a period of time (in milliseconds).
  }


  for(int j = 0; j< 20; ++j)
  {
    for(int i = 0; i < 5; ++i)
    {
      setAllPixels(0,0,0);
      delay(100); // Delay for a period of time (in milliseconds).
    
      setAllPixels(255,0,0);
      delay(10); // Delay for a period of time (in milliseconds).
    }
    for(int i = 0; i < 5; ++i)
    {
      setAllPixels(0,0,0);
      delay(100); // Delay for a period of time (in milliseconds).
    
      setAllPixels(0,0,255);
      delay(10); // Delay for a period of time (in milliseconds).
    }
  }
  */
}

void setAllPixels(int r, int g, int b)
{
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(r,g,b)); 
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
}
