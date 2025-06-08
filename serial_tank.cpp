#include "serial_tank.h"
#include "Arduino.h"
#include "main.h"

unsigned int volume_value;
unsigned char valueh, valuel;

void init_serial_tank(void) {
    Serial.begin(19200);
    Serial.write(0xFF);  // sync communication
    Serial.write(0xFF);
    Serial.write(0xFF);   
}

unsigned int volume(void) {
    Serial.write(VOLUME_REQUEST);  
    // Request volume
    delay(100); // Give time to respond

    if (Serial.available() >= 2) {
        valueh = Serial.read();
        valuel = Serial.read();
        volume_value = ((unsigned int)valueh << 8) | valuel;

        return volume_value;
    } else {
        return 0;
    }
}

void enable_inlet(void) {
    Serial.write(INLET_VALVE);
    Serial.write(ENABLE);
}

void disable_inlet(void) {
    Serial.write(INLET_VALVE);
    Serial.write(DISABLE);
}

void enable_outlet(void) {
    Serial.write(OUTLET_VALVE);
    Serial.write(ENABLE);
}

void disable_outlet(void) {
    Serial.write(OUTLET_VALVE);
    Serial.write(DISABLE);
}
