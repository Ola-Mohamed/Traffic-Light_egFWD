/******************************************************************************
 *
 * Module: PUSH BUTTON
 *
 * File Name: Test_PUSH_BUTTON.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#ifndef ECUAL_PUSH_BUTTON_TEST_PUSH_BUTTON_H_
#define ECUAL_PUSH_BUTTON_TEST_PUSH_BUTTON_H_

//Here we make a test for LEDS & Push button
#include "PUSH_BUTTON.h"
#include "../LEDS/LED.h"

 void Testing_Push_Button_and_LEDS ()
 {
	  // TESTING Buttons DRIVER ////
	 ledInit (PORTA_ID,PIN5_ID);
	 PushButtonInit(PORTD_ID, PIN2_ID);

	  while (1)
	  {
		  uint8_t button_state ;
		  BUTTON_READ(PORTD_ID, PIN2_ID, &button_state );

		  if (button_state == 1)
		  {
			  ledOn(PORTA_ID,PIN5_ID);
		  }
		  else if (button_state == 0)
		  {
			  ledOff (PORTA_ID,PIN5_ID);
		  }

	  }
 }
#endif /* ECUAL_PUSH_BUTTON_TEST_PUSH_BUTTON_H_ */
