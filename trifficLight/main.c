 /******************************************************************************
 *
 * File Name: Main.c
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/
#include "APP/APP.h"
#include"MCAL/TIMER/Test_TIMER.h"
#include"MCAL/INT/Test_INT.h"
#include"ECUAL/PUSH_BUTTON/Test_PUSH_BUTTON.h"

int main(void){
/*
	app_inits();

	 while(1){
	 	app_start();
	 }*/

	Testing_Timers();
    //Test_INT();
	//Testing_Push_Button_and_LEDS();
}

