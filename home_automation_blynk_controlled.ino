#define BLYNK_TEMPLATE_ID "TMPL2D0MPghjL"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "eKQ9jWsWRzQ8cnntz65t3406vou4M79H"

#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "main.h"
#include "temperature_system.h"
#include "ldr.h"
#include "serial_tank.h"

char auth[] = BLYNK_AUTH_TOKEN;

bool heater_sw, inlet_sw, outlet_sw, cooler_sw;
unsigned int tank_volume;

BlynkTimer timer;
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* To Turn on/off the cooler based on the virtual pin value */
BLYNK_WRITE(COOLER_V_PIN) {
  cooler_sw = param.asInt(); // ✅ Fix: variable was used incorrectly
  if (cooler_sw) {
    cooler_control(ON);
    lcd.setCursor(7, 1);
    lcd.print("CLR_ON ");
  } else {
    cooler_control(OFF);
    lcd.setCursor(7, 1);
    lcd.print("CLR_OFF");
  }
}

/* To Turn on/off the heater based on the virtual pin value */
BLYNK_WRITE(HEATER_V_PIN) {
  heater_sw = param.asInt();
  if (heater_sw) {
    heater_control(ON);
    lcd.setCursor(7, 1);
    lcd.print("HT_ON");
  } else {
    heater_control(OFF);
    lcd.setCursor(7, 1);
    lcd.print("HT_OFF");
  }
}

BLYNK_WRITE(INLET_V_PIN) {
  inlet_sw = param.asInt();
  if (inlet_sw) {
    enable_inlet();
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_ON ");
  } else {
    disable_inlet();
    lcd.setCursor(8, 0);
    lcd.print("IN_FL_OFF");
  }
}

BLYNK_WRITE(OUTLET_V_PIN) {
  outlet_sw = param.asInt();
  if (outlet_sw) {
    enable_outlet();
    lcd.setCursor(7, 1);
    lcd.print("OUTLET_ON");
  } else {
    disable_outlet();
    lcd.setCursor(7, 0);
    lcd.print("OUTLET_OFF");
  }
}

void update_temperature_reading() {
  Blynk.virtualWrite(TEMPERATURE_GAUGE, read_temperature()); // ✅ Fix: call the function
}

void handle_temp(void) {
  if (read_temperature() > 35.0 && heater_sw) {
    heater_sw = 0;
    heater_control(OFF);
    Blynk.virtualWrite(HEATER_V_PIN, 0);
    Blynk.virtualWrite(BLYNK_TERMINAL_V_PIN, "Temperature > 35°C. Heater OFF\n");
    lcd.setCursor(7, 1);
    lcd.print("HAET_OFF");
  } else if (read_temperature() < 25.0) {
    heater_sw = 1;
    heater_control(ON);
    Blynk.virtualWrite(HEATER_V_PIN, 1);
    lcd.setCursor(7, 1);
    lcd.print("HT_ON ");
  }
}

void handle_tank(void) {
  tank_volume = volume();
  if (tank_volume < 2000 && inlet_sw == 0) {
    enable_inlet();
    inlet_sw = 1;
    Blynk.virtualWrite(INLET_V_PIN, 1);
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_ON ");
  } else if (tank_volume > 1950 && inlet_sw == 1) {
    disable_inlet();
    inlet_sw = 0;
    Blynk.virtualWrite(INLET_V_PIN, 0);
    lcd.setCursor(7, 1);
    lcd.print("IN_FL_OFF");
  }
}

void setup(void) {
  Serial.begin(19200);
  Blynk.begin(auth);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Home Automation");
  lcd.setCursor(0, 1);
  lcd.print("T=");
  lcd.setCursor(8, 1);
  lcd.print("V=");

  init_serial_tank();
  init_ldr();
  init_temperature_system();

  timer.setInterval(1000, update_temperature_reading);
  timer.setInterval(2000, handle_temp);
  timer.setInterval(3000L, handle_tank);
}

void loop() {
  brightness_control();

  String temp = String(read_temperature(), 2);
  lcd.setCursor(2, 0);
  lcd.print("Temp: ");
  lcd.print(temp);

  tank_volume = volume();
  lcd.setCursor(2, 1);
  lcd.print("Volume: ");
  lcd.print(tank_volume);

  Blynk.run();
  timer.run();
}
