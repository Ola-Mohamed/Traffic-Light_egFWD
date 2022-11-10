 /******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name:  INT.c
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#include"INT.h"


/*******************************************************************************
 *                      Functions                                              *
 *******************************************************************************/
void Exi0Init()
{
	DDRD  &= (~(1<<PD2));                // Configure INT0/PD2 as input pin
	PORTD |= (1<<PD2);					 //enabling Pull-up for the pin
	GICR  |= (1<<INT0);                  // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC01);  				 // Trigger INT0 with the falling edge
	GIFR   = (1<<INTF0);				 // Disabling INT0 flag manually to avoid any errors
}

// function to enable global interrupt
void Exi0Enable (void)
{
	SET_BIT(SREG,7);
}

// function to disable global interrupt

void Exi0Disable (void)
{
	CLEAR_BIT(SREG,7);
}
