#include "temperature_system.h"
#include "Arduino.h"
#include "main.h"

void init_temperature_system(void) {

    pinMode(HEATER, OUTPUT);
    pinMode(COOLER, OUTPUT);
    pinMode(TEMPERATURE_SENSOR, INPUT); // Set temperature sensor pin as input
}

float read_temperature(void) {

    int sensor_value = analogRead(TEMPERATURE_SENSOR);   // Read analog value
    float voltage = sensor_value * (5.0 / 1023.0);        // Convert to voltage
    float temperature = voltage * 100.0;                  // LM35: 10mV per °C
    return temperature;
}

void cooler_control(bool control) {
    digitalWrite(COOLER, control ? HIGH : LOW);
}

void heater_control(bool control) {
    digitalWrite(HEATER, control ? HIGH : LOW);
}
