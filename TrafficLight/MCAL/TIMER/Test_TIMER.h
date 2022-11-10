 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Test_Timer.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#ifndef MCAL_TIMER_TEST_TIMER_H_
#define MCAL_TIMER_TEST_TIMER_H_

#include"TIMER.h"
#include "../../ECUAL/LEDS/LED.h"

void Testing_Timers(void)
{
	ledInit (PORTA_ID,PIN5_ID);
	while (1)
	{
		ledOff(PORTA_ID,PIN5_ID);
		Timer0_Delay(20);
		ledOn(PORTA_ID,PIN5_ID);
		Timer0_Delay(20);
	}
}

#endif /* MCAL_TIMER_TEST_TIMER_H_ */
