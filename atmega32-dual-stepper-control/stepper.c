#include "stepper.h"

static uint8_t step1 = 0;
static uint8_t step2 = 0;

// motor 1
void Stepper1Setup(void)
{
	DDRB |= (1<<PB0) |
			(1<<PB1) |
			(1<<PB2) |
			(1<<PB3);

	PORTB |= (1<<PB0) |
			 (1<<PB1) |
			 (1<<PB2) |
			 (1<<PB3);
}

static void Stepper1Output(uint8_t phase)
{
	PORTB |= (1<<PB0) |
			 (1<<PB1) |
			 (1<<PB2) |
			 (1<<PB3);

	switch(phase)
	{
		case 0: PORTB &= ~(1<<PB0); break;
		case 1: PORTB &= ~(1<<PB1); break;
		case 2: PORTB &= ~(1<<PB2); break;
		case 3: PORTB &= ~(1<<PB3); break;
	}
}

void Stepper1Step(StepperDirection direction)
{
	if(direction == STEPPER_RIGHT)
	{
		step1++;

		if (step1 > 3)
			step1 = 0;
	}
	else
	{
		if (step1 == 0)
			step1 = 3;
		else
			step1--;
	}

	Stepper1Output(step1);
}


// motor 2 
void Stepper2Setup(void)
{
	DDRB |= (1<<PB4) |
			(1<<PB5) |
			(1<<PB6) |
			(1<<PB7);

	PORTB |= (1<<PB4) |
			 (1<<PB5) |
			 (1<<PB6) |
			 (1<<PB7);
}

static void Stepper2Output(uint8_t phase)
{
	PORTB |= (1<<PB4) |
			 (1<<PB5) |
			 (1<<PB6) |
			 (1<<PB7);

	switch(phase)
	{
		case 0: PORTB &= ~(1<<PB4); break;
		case 1: PORTB &= ~(1<<PB5); break;
		case 2: PORTB &= ~(1<<PB6); break;
		case 3: PORTB &= ~(1<<PB7); break;
	}
}

void Stepper2Step(StepperDirection direction)
{
	if(direction == STEPPER_RIGHT)
	{
		step2++;

		if (step2 > 3)
			step2 = 0;
	}
	else
	{
		if (step2 == 0)
			step2 = 3;
		else
			step2--;
	}

	Stepper2Output(step2);
}