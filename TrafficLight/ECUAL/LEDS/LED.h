/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#ifndef ECUAL_LEDS_LED_H_
#define ECUAL_LEDS_LED_H_

#include"../../MCAL/GPIO/GPIO.h"

void ledInit(uint8  port_num  ,uint8 pinnum );

void ledOn(uint8  port_num  ,uint8 pinnum);

void ledOff(uint8  port_num  ,uint8 pinnum);

void ledToggle (uint8 port_num  , uint8 pin_num);

#endif /* ECUAL_LEDS_LED_H_ */
