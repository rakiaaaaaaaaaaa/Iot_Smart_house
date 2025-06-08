
#ifndef SERIAL_TANK_H
#define SERIAL_TANK_H

// Command definitions
#define INLET_VALVE      0x00
#define OUTLET_VALVE     0x01

#define ENABLE           0x01
#define DISABLE          0x00

// Sensor request commands
#define HIGH_FLOAT       0x10
#define LOW_FLOAT        0x11
#define VOLUME_REQUEST   0x30

// Function declarations
void init_serial_tank(void);
void enable_inlet(void);
void disable_inlet(void);
void enable_outlet(void);
void disable_outlet(void);
unsigned int volume(void);

#endif
