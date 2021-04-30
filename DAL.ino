#include "core.h"

void setup() {
  
  
  /*********** DEBUG ************/
  Serial.begin(9600);
  /*********** DEBUG ************/
  
  /*********** SETUP PINS ************/
  RED_PIN = 2;
  GREEN_PIN = 3;
  BLUE_PIN = 4;

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  /********* END SETUP PINS **********/

  /* Start with LEDs OFF */
  setColorRGB(0,0,0);


  for (int velocity = 4; velocity < 6; velocity++) {
    for (int rpm = MIN_RPM; rpm < MAX_RPM; rpm++) {
      Serial.println(rpm);
      setLED(rpm, velocity);
      delay(2);
    }
  }
}

void loop () {

}
