#ifndef LDR_H
#define LDR_H

// Corrected to match your hardware configuration from images
#define LDR_SENSOR  A0    // Matches your LDR module connected to A0 
#define GARDEN_LIGHT 5    // Changed to PD3/2 (Pin 5) from image 4.jpg (D1 is connected here)

void init_ldr(void);
void brightness_control(void);

#endif