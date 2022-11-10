/******************************************************************************
 *
 * Module: PUSH BUTTON
 *
 * File Name: PUSH BUTTON.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#ifndef ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_
#define ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_

#include"../../MCAL/GPIO/GPIO.h"

void PushButtonInit(uint8 port_num  ,uint8 pin_num );
void BUTTON_READ(uint8 port_num, uint8 pin_num, uint8 * value);

#endif /* ECUAL_PUSH_BUTTON_PUSH_BUTTON_H_ */
