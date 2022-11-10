/******************************************************************************
 *
 * Module: PUSH BUTTON
 *
 * File Name: PUSH BUTTON.c
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#include"PUSH_BUTTON.h"


void PushButtonInit(uint8 port_num  ,uint8 pin_num ){

	GPIO_setupPinDirection( port_num,  pin_num, 0);

}

void BUTTON_READ(uint8 port_num, uint8 pin_num, uint8 * value)
{
	GPIO_readPin(port_num, pin_num );

}
