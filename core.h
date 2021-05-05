#include "led.h"
#include "car.h"

#define MIN_LOW_HUE 240
#define MAX_LOW_HUE 165

#define MIN_MID_HUE 165
#define MAX_MID_HUE 80

#define MIN_HI_HUE 80
#define MAX_HI_HUE 0

int getHue(int rpm) {
   /*
    * a * MIN_RPM + b = MIN_HUE
    * a * MAX_RPM + b = MAX_HUE
    * 
    * a = (MAX_HUE - MIN_HUE) / (MAX_RPM - MIN_RPM);
    * b = MIN_HUE - a * MIN_RPM;
   */

  int min_hue = 0, max_hue = 1;
  int min_rpm = 0, max_rpm = 1;

  if (rpm <= MAX_LOW_RPM && rpm >= MIN_LOW_RPM) {
    min_hue = MIN_LOW_HUE;
    max_hue = MAX_LOW_HUE;
    min_rpm = MIN_LOW_RPM;
    max_rpm = MAX_LOW_RPM;
  }
  if (rpm <= MAX_MID_RPM && rpm >= MIN_MID_RPM) {
    min_hue = MIN_MID_HUE;
    max_hue = MAX_MID_HUE;
    min_rpm = MIN_MID_RPM;
    max_rpm = MAX_MID_RPM;
  }
  if (rpm <= MAX_HI_RPM && rpm >= MIN_HI_RPM) {
    min_hue = MIN_HI_HUE;
    max_hue = MAX_HI_HUE;
    min_rpm = MIN_HI_RPM;
    max_rpm = MAX_HI_RPM;
  }
     
  double a = (double)(max_hue - min_hue) / (max_rpm - min_rpm);
  double b = min_hue - a * min_rpm;


  Serial.print(a);
  Serial.print("  - ");
  Serial.print(b);
  Serial.print("\t");
  return (int) (a * rpm + b);

}

void setLED(int rpm, int velocity) {
  int H = getHue(rpm);
  double S = 1.0;
  double V = 1.0;
  if (velocity < 5) {
    V = 0.4;
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
