#define F_CPU 11059200
#include <avr/io.h>
#include <util/delay.h>

void LCD_Init(void)
{
	DDRC  |=   (1<<PC7)/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;	// Set LCD backlight control pin as output
	PORTC |=   (1<<PC7)/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;	// Turn on LCD backlight

// Configure all four data lines as outputs
	//	PD7		PD6		PD5		PD4
	DDRC  |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/ ;
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/);
	//	E		RW		RS
	DDRC  |= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) | (1<<PC1) | (1<<PC0)   ;
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) | (1<<PC1) | (1<<PC0)   ;
	_delay_ms(15);
	
	//	E		RW		RS
	PORTC &=~(/*(1<<PC6)| (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) | (1<<PC1) | (1<<PC0))  ;
	//	E
	PORTC |= /* (1<<PC6)| (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	//		 PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/ ;	// 8-bit mode
	//	E
	PORTC &= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	_delay_ms(5);

	//	E
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	//		 PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/ ;	// 8-bit mode
	// E
	PORTC &= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	_delay_us(100);

	//	E
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	//		 PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/ ;	// 8-bit mode
	// E
	PORTC &= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	_delay_us(100);

	//	E
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC1) | (1<<PC0)*/ ;
	//		 PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC1) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC1) | (1<<PC0)*/ ;	// 4-bit mode
	//	RS
	PORTC &= /*(1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC1) | (1<<PC0)*/;
	_delay_us(100);

// Busy flag can now be used
	
// 4-bit mode, 2 lines, 5x7 character font
	//	E
	PORTC |=   (1<<PC2);
	//	PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	PORTC |=					(1<<PC4);
	//	E
	PORTC &=  ~(1<<PC2);
	//	E
	PORTC |=   (1<<PC2);
	// PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	PORTC |=   (1<<PC6);
	//	E
	PORTC &=  ~(1<<PC2);
	_delay_us(100);
	
// Disable cursor
// Enable display
	//	E
	PORTC |=   (1<<PC2);
	//	PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	//	E
	PORTC &=  ~(1<<PC2);
	//	E
	PORTC |=   (1<<PC2);
	// PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	PORTC |=   (1<<PC6) | (1<<PC5);
	//	E
	PORTC &=  ~(1<<PC2);
	_delay_us(100);
	
// Move cursor right without shifting display contents
	//	E
	PORTC |=   (1<<PC2);
	//	PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	//	E
	PORTC &=  ~(1<<PC2);
	//	E
	PORTC |=   (1<<PC2);
	// PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	PORTC |=			(1<<PC5) | (1<<PC4);
	//	E
	PORTC &=  ~(1<<PC2);
	_delay_us(100);
	
// Clear display
	//	E
	PORTC |=   (1<<PC2);
	//	PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	//	E
	PORTC &=  ~(1<<PC2);
	//	E
	PORTC |=   (1<<PC2);
	// PD7		PD6		PD5		PD4
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3));
	PORTC |=   (1<<PC3);
	//	E
	PORTC &=  ~(1<<PC2);
	_delay_ms(100);
}

void LCD_MenuTop(void)
{
// Top line
	//	0. RS
	PORTC &= ~(/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0));
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) /*(1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~((1<<PC2)) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter >
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;

	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;

	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;

	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;

	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter G
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2)/* (1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=  /*(1<<PC6)|*/(1<<PC5)| (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter r
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) */(1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter a
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4)*/ (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter /
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6) |(1<<PC5)*/  (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter D
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2)/* (1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=  /*(1<<PC6)|*/(1<<PC5)/*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter l
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Botton line
	//	0. RS
	PORTC &= ~(/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0));
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~((1<<PC2)) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4)/*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter P
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) |/*(1<<PC4)*/(1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter r
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) */(1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


	// Letter a
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4)*/ (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter w
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter /
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6) |(1<<PC5)*/  (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter L
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5)/* (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter e
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5)/*(1<<PC4)*/| (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter w
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
	// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
}


void LCD_MenuBottom(void)
{
// Top line
	//	0. RS
	PORTC &= ~(/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0));
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) /*(1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~((1<<PC2)) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter >
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;

	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;

	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;

	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);

	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter G
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2)/* (1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=  /*(1<<PC6)|*/(1<<PC5)| (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter r
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) */(1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter a
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4)*/ (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter /
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6) |(1<<PC5)*/  (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter D
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2)/* (1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=  /*(1<<PC6)|*/(1<<PC5)/*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter l
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Botton line
	//	0. RS
	PORTC &= ~(/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0));
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~((1<<PC2)) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter >
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;

	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5)*/ (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;

	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;

	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;

	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;

	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter P
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) |/*(1<<PC4)*/(1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter r
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) */(1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);


// Letter a
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6) | (1<<PC5) | (1<<PC4)*/ (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter w
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter /
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6) |(1<<PC5)*/  (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter L
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5)/* (1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) /*(1<<PC4) | (1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter e
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5)/*(1<<PC4)*/| (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter w
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |= /*(1<<PC6)*/ (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
	
// Letter o
	//	0. RS
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) | (1<<PC2)*/ (1<<PC0)	 ;
	
	//	1. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	//	2. PD7		PD6		PD5		PD4		- four older bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3) /*(1<<PC2) | (1<<PC0)*/);
	PORTC |=/* (1<<PC6)*/ (1<<PC5) | (1<<PC4) /*(1<<PC3) | (1<<PC2) | (1<<PC0)*/ ;
	
	//	3. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ ~(1<<PC2)/*(1<<PC0)*/ ;
	
	//	4. E up
	PORTC |=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/ (1<<PC2) /*(1<<PC0)*/ ;
	
	// 5. PD7		PD6		PD5		PD4		- four younger bits
	PORTC &= ~((1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/);
	PORTC |=   (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)/* (1<<PC2) | (1<<PC0)*/ ;
	
	//	6. E down
	PORTC &=/* (1<<PC6) | (1<<PC5) | (1<<PC4) | (1<<PC3)*/~(1<<PC2) /*(1<<PC0)*/ ;
	_delay_us(50);
	
}