#include "core.h"

void setup() {
  
  
  /*********** DEBUG ************/
  Serial.begin(9600);
  /*********** DEBUG ************/
  
  /*********** SETUP PINS ************/
  RED_PIN = 9;
  GREEN_PIN = 10;
  BLUE_PIN = 11;

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  /********* END SETUP PINS **********/

  /* Start with LEDs OFF */
  setColorRGB(0,0,0);


  for (int velocity = 4; velocity < 6; velocity++) {
    for (int rpm = 700; rpm < 6000; rpm++) {
      Serial.print(rpm);
      Serial.print("\t");
      setLED(rpm, velocity);
      delay(2);
    }
  }
}

void loop () {

}
