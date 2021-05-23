#include "core.h"
#include "bluetooth.h"
#include "ELM327.h"
#include <string.h>

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

  /********* WAIT FOR BLUETOOTH TO CONNECT **********/
  delay(10000); // 10s  


//  for (int velocity = 4; velocity < 6; velocity++) {
//    for (int rpm = 700; rpm < 6000; rpm++) {
//      Serial.print(rpm);
//      Serial.print("\n");
//      setLED(rpm, velocity);
//      delay(2);
//    }
//  }
  
  
  /* Start with LEDs OFF */
  setColorRGB(255,0,0);
  BT_init();
  
  /* Start with LEDs OFF */
  setColorRGB(0,0,255);
  ELM_init();
  
  /* Start with LEDs OFF */
  setColorRGB(0,255,0);
  delay(1000);
}

void loop () {
  int RPM = get_RPM();
//  int velocity = get_speed();

  Serial.print(RPM);
//  Serial.print(" - ");
//  Serial.println(velocity);

  if (RPM < MIN_LOW_RPM && RPM > 10) {
    ELM_init();
  }

  setLED(RPM, 10);
 
}
