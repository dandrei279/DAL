#include "led.h"
#include "car.h"

#define MIN_HUE 255  // blue
#define MAX_HUE 0    // red

int getHue(int rpm) {
   /*
    * a * MIN_RPM + b = MIN_HUE
    * a * MAX_RPM + b = MAX_HUE
    * 
    * a = (MAX_HUE - MIN_HUE) / (MAX_RPM - MIN_RPM);
    * b = MIN_HUE - a * MIN_RPM;
   */
   
  static double a = (double)(MAX_HUE - MIN_HUE) / (MAX_RPM - MIN_RPM);
  static double b = MIN_HUE - a * MIN_RPM;
  
  return (int) (a * rpm + b);

}

void setLED(int rpm, int velocity) {
  int H = getHue(rpm);
  double S = 1.0;
  double V = 1.0;
  if (velocity < 5) {
    V = 0.65;
  }
/*
  Serial.print(H);
  Serial.print(",");
  Serial.print(S);
  Serial.print(",");
  Serial.println(V);
  */

  setLedColorHSV(H, S, V);
  
}
