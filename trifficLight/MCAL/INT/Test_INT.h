 /******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name:  Test_INT.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#ifndef MCAL_INT_TEST_INT_H_
#define MCAL_INT_TEST_INT_H_

#include "../../ECUAL/LEDS/LED.h"
#include "../TIMER/TIMER.h"
#include "INT.h"
#include "../../ECUAL/PUSH_BUTTON/PUSH_BUTTON.h"

void Test_INT()
{

	ledInit (PORTA_ID,PIN5_ID);
	PushButtonInit(PORTD_ID, PIN2_ID);
	Exi0Init();
    Exi0Enable();
    ledOn(PORTA_ID,PIN5_ID);

}













#endif /* MCAL_INT_TEST_INT_H_ */
