#include "joystick.h"

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

static uint8_t x_addr;
static uint8_t y_addr;
static uint8_t sw_pin;

static void ADC_Init(void)
{
	ADMUX = (1 << REFS0);	// 5V

	ADCSRA = (1 << ADEN)	// ADC on
			|(1 << ADPS2)	// pre-
			|(1 << ADPS1)	// ska-
			|(1 << ADPS0);	// ler 128 
}

static uint16_t ADC_Read(uint8_t channel)
{
	ADMUX = (1 << REFS0) | channel;

	ADCSRA |= (1 << ADSC);

	while (ADCSRA & (1 << ADSC));

	return ADC;
}

void JoystickSetup (uint8_t pin_x, 
					uint8_t pin_y,
					uint8_t switch_pin)
{
	x_addr = pin_x;
	y_addr = pin_y;
	sw_pin = switch_pin;
	
	DDRA &= ~(1<<pin_x);
	DDRA &= ~(1<<pin_y);
	
	DDRA &= ~(1<<sw_pin);
	PORTA |= (1<<sw_pin);
	
	ADC_Init();
}

void JoystickADC(JoystickPosition *pozycja)
{
	pozycja -> axis_x = ADC_Read(x_addr);
	pozycja -> axis_y = ADC_Read(y_addr);
}

uint8_t JoystickSwitchPressed(void)
{
	if(!(PINA & (1 << sw_pin)))
	{
		_delay_ms(20);

		if(!(PINA & (1 << sw_pin)))
		{
			while(!(PINA & (1 << sw_pin)));

			return 1;
		}
	}

	return 0;
}