/******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.c
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#include"LED.h"

/*******************************************************************************
 *                              Functions                                      *
 *******************************************************************************/

void ledInit(uint8 port_num  ,uint8 pin_num ){

	GPIO_setupPinDirection( port_num,  pin_num, 1);
}

void ledOn(uint8  port_num ,uint8 pin_num){

	GPIO_writePin(port_num,pin_num, 1);       //Set the given pin in the given port to one(on)
}

void ledOff(uint8  port_num  ,uint8 pin_num){

	GPIO_writePin( port_num,  pin_num ,0);      //Set the given pin in the given port to zero(off)
}

void ledToggle (uint8 port_num  , uint8 pin_num)
{
		GPIO_toggle(port_num,pin_num);
}
