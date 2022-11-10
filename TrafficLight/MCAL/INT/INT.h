 /******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name:  INT.h
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#ifndef MCAL_INT_INT_H_
#define MCAL_INT_INT_H_

#include "../../Utilites/Types.h"
#include "../../Utilites/CommonMacros.h"
#include "../../Utilites/MacroConfig.h"
#include "../../ECUAL/LEDS/LED.h"
#include "../../MCAL/TIMER/TIMER.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Exi0Init(void);
void Exi0Enable (void);
void Exi0Disable (void);
#endif /* MCAL_INT_INT_H_ */
