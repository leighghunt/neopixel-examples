// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


// this constant won't change:
const int  buttonPinIncrease = 2;    // the pin that the pushbutton is attached to
const int  buttonPinDecrease = 5;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounterIncrease = 0;   // counter for the number of button presses
int buttonPushCounterDecrease = 0;   // counter for the number of button presses
int buttonStateIncrease = 0;         // current state of the button
int buttonStateDecrease = 0;         // current state of the button
int lastButtonStateIncrease = 0;     // previous state of the button
int lastButtonStateDecrease = 0;     // previous state of the button

bool decrease = false;
bool increase = false;
int lightValue = 0;

int msIncreaseButtonOn = 0;
int msDecreaseButtonOn = 0;


int delayval = 5; 
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPinIncrease, INPUT);
  pinMode(buttonPinDecrease, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // read the pushbutton input pin:
  buttonStateIncrease = digitalRead(buttonPinIncrease);
  buttonStateDecrease = digitalRead(buttonPinDecrease);

  // compare the buttonState to its previous state
  if (buttonStateIncrease != lastButtonStateIncrease) {
    // if the state has changed, increment the counter
    if (buttonStateIncrease == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      increase = true;
      msIncreaseButtonOn = millis();
      buttonPushCounterIncrease++;
      Serial.println("Increase on");
      Serial.print("number of Increase button pushes:  ");
      Serial.println(buttonPushCounterIncrease);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      msIncreaseButtonOn = 0;
      increase = false;
      Serial.println("Increase off"); 
    }
  }
 
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonStateIncrease = buttonStateIncrease;

  
  // compare the buttonState to its previous state
  if (buttonStateDecrease != lastButtonStateDecrease) {
    // if the state has changed, increment the counter
    if (buttonStateDecrease == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      decrease = true;
      buttonPushCounterDecrease++;
      Serial.println("Decrease on");
      Serial.print("number of Decrease button pushes:  ");
      Serial.println(buttonPushCounterDecrease);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      decrease = false;
      Serial.println("Decrease off"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonStateDecrease = buttonStateDecrease;

  if(increase)
  {
    if(lightValue<255 * NUMPIXELS)
    {
      ++lightValue;
    }
  }

  if(decrease)
  {
    if(lightValue>0)
    {
      --lightValue;
    }
  }

  // Square curve
  double adjustedLightValue = lightValue/(255*NUMPIXELS);
  adjustedLightValue *= adjustedLightValue;
  adjustedLightValue = lightValue*(255*NUMPIXELS);
  
  if(msIncreaseButtonOn > 0 && (millis() - msIncreaseButtonOn) > 1000);

  for(int i=0;i<NUMPIXELS;i++){
    int pixelValue = (lightValue + i)/NUMPIXELS;
    //Serial.println(pixelValue);
    pixels.setPixelColor(i, pixels.Color(pixelValue,pixelValue,pixelValue));
  }
  pixels.show();
  delay(5);

}

