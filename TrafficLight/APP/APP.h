 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../ECUAL/LEDS/LED.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/INT/INT.h"
#include "../ECUAL/PUSH_BUTTON/PUSH_BUTTON.h"

typedef unsigned char boolean;


/*******************************************************************************
 *                      Functions                                              *
 *******************************************************************************/
void app_inits(void);
void app_start(void);
void Blinking_yellow ();
void PED_Mood();



#endif /* APP_APP_H_ */
