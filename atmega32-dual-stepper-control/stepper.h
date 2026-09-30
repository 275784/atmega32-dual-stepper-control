#ifndef STEPPER_H_
#define STEPPER_H_

#include <avr/io.h>
#include <stdint.h>

typedef enum
{
	STEPPER_LEFT,
	STEPPER_RIGHT

} StepperDirection;

void Stepper1Setup(void);
void Stepper2Setup(void);

void Stepper1Step(StepperDirection direction);
void Stepper2Step(StepperDirection direction);

#endif