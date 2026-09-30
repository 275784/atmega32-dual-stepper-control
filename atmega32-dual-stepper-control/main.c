#define F_CPU 11059200UL

#include <avr/io.h>
#include <util/delay.h>

#include "lcd.h"
#include "joystick.h"
#include "stepper.h"

#define JOY_MIN 400
#define JOY_MAX 600

// 0 - left/right
// 1 - up/down
uint8_t menu = 0;
JoystickPosition joy;

int main(void)
{
	JoystickSetup(0, 1, 2);
	
	Stepper1Setup();
	Stepper2Setup();
	
	LCD_Init();
	LCD_MenuTop();

	while(1)
	{
		if(JoystickSwitchPressed())
		{
			if(menu == 0)
			{
				menu = 1;
				LCD_MenuBottom();
			}
			else
			{
				menu = 0;
				LCD_MenuTop();
			}
		}
		
		JoystickADC(&joy);

		if(menu == 0) // left/right
		{
			if(joy.axis_x > JOY_MAX)
			{
				Stepper1Step(STEPPER_RIGHT);
				_delay_ms(20);
			}
			else if(joy.axis_x < JOY_MIN)
			{
				Stepper1Step(STEPPER_LEFT);
				_delay_ms(20);
			}
		}
		
		if(menu == 1) // up/down
		{
			if(joy.axis_y > JOY_MAX)
			{
				Stepper2Step(STEPPER_RIGHT);
				_delay_ms(20);
			}
			else if(joy.axis_y < JOY_MIN)
			{
				Stepper2Step(STEPPER_LEFT);
				_delay_ms(20);
			}
		}
	}
}