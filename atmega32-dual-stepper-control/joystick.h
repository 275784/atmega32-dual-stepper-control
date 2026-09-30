#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include <avr/io.h>
#include <stdint.h>

#define JOYSTICK_ADC_MAX_VALUE 1023

typedef struct JoystickPosition
{
	uint16_t axis_x;
	uint16_t axis_y;
} JoystickPosition;

void JoystickSetup (uint8_t pin_x, 
					uint8_t pin_y,
					uint8_t switch_pin);

void JoystickADC(JoystickPosition *pozycja);

uint8_t JoystickSwitchPressed(void);

#endif /* JOYSTICK_H_ */