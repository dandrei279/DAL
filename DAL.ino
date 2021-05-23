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
  /* 
   *  The circuit can be dimmed depending on the velocity of the car.  
   *  However it takes time to get the speed of tha car and this will make
   *  the system more slow.
   *  
   *  If you want to test that, just uncomment the lines below
   */
  int RPM = get_RPM();
//  int velocity = get_speed();

  Serial.print(RPM);
//  Serial.print(" - ");
//  Serial.println(velocity);

  // if the ignition is turned off, reset the connection.
  if (RPM < MIN_LOW_RPM && RPM > 10) {
    ELM_init();
  }

  setLED(RPM, 10);
}
