#include "ldr.h"
#include "Arduino.h"
#include "main.h"



void init_ldr(void) {
  pinMode(GARDEN_LIGHT, OUTPUT);  // Set light pin as output
  pinMode(LDR_SENSOR, INPUT);    // Set LDR pin as input
  analogWrite(GARDEN_LIGHT, 0);        // Initialize with light off

}




void brightness_control(void) {
  unsigned int adc_val =analogRead(LDR_SENSOR) ;

  //scale it down from (0 255) and reverse it from (255 to 0)
  adc_val = map(adc_val, 0, 255, 255, 0);    

  //map (0, 1023, 255,0)

  analogWrite (GARDEN_LIGHT, adc_val);
  

 
}
