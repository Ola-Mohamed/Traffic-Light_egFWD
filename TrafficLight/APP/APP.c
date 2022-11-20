 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: APP.c
 *
 * Author: Ola Mohamed Ahmed
 *
 *******************************************************************************/

#include "APP.h"

/*******************************************************************************
 *                      Global Variables                                       *
 *******************************************************************************/

 boolean Yellow_is_blinking=0;
 boolean buttonClick =0;


/*******************************************************************************
 *                      Functions                                              *
 *******************************************************************************/

/*******************************************************************************
 * [Function Name] : app_inits
 *
 * [Description]   : Function to intilization the moduels of program
 *
 * [Args in]       : NONE
 * [Args out]      : NONE
 *******************************************************************************/
void app_inits(void){

	// Initializing Direction and Value of LED DIO PINS
	//car_LEDS
	ledInit(PORTA_ID,PIN0_ID); //green
	ledInit(PORTA_ID,PIN1_ID); //Yellow
	ledInit(PORTA_ID,PIN2_ID); //red

    //pedestrian_LEDS
	ledInit(PORTB_ID,PIN0_ID); //green
	ledInit(PORTB_ID,PIN1_ID); //Yellow
	ledInit(PORTB_ID,PIN2_ID); //red

	// initializing Interrupt Button Pin
	//PushButtonInit(PORTD_ID,PIN2_ID); //INT0


	//Initializing INTERRUPT 0
	Exi0Init();
   //Enable INTERRUPT 0
	Exi0Enable();

}

/*******************************************************************************
 * [Function Name] : app_start
 *
 * [Description]   : Function to be called when normal routine
 *
 * [Args in]       : NONE
 * [Args out]      : NONE
 *******************************************************************************/
void app_start(void){

	// Green led for cars & Red led for ped. is on for five seconds
	 ledOn(PORTA_ID,PIN0_ID);
	 ledOn(PORTB_ID,PIN2_ID);
	 buttonClick=1;
	 Timer0_Delay(20);

     // After 5 second  Green led for cars & Red led for ped. switched OFF
     // And yellow LEDs of both will blinking for five second
     ledOff(PORTA_ID,PIN0_ID);
     ledOff(PORTB_ID,PIN2_ID);
     buttonClick=0;
     Blinking_yellow();
     ledOff(PORTA_ID,PIN1_ID);
     ledOff(PORTB_ID,PIN1_ID);


     // After yellow blinking for 5 seconds
     // Red led for cars & green led for ped. is on for five seconds
     // then yellow blinking again

     ledOn(PORTA_ID,PIN2_ID);
     ledOn(PORTB_ID,PIN0_ID);
     Timer0_Delay(20);
     ledOff(PORTA_ID,PIN2_ID);
     ledOff(PORTB_ID,PIN0_ID);

     Blinking_yellow();

     ledOff(PORTA_ID,PIN1_ID);
     ledOff(PORTB_ID,PIN1_ID);
     app_start();


}
/*******************************************************************************
 * [Function Name] : Blinking_yellow
 *
 * [Description]   : Function to toggles the yellow leds of both cars and ped. every 500 ms for 5
 *
 * [Args in]       : NONE
 * [Args out]      : NONE
 *******************************************************************************/
void Blinking_yellow()
{

	 Yellow_is_blinking = 1;

	 ledToggle(PORTA_ID,PIN1_ID);
	 ledToggle(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	ledToggle(PORTA_ID,PIN1_ID);
	ledToggle(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
	Timer0_Delay(5);

	ledToggle(PORTA_ID,PIN1_ID);
	ledToggle(PORTB_ID,PIN1_ID);   // YELLOW LED FOR PEDESTRIANS
	Timer0_Delay(5);

	ledToggle(PORTA_ID,PIN1_ID);
	ledToggle(PORTB_ID,PIN1_ID);   // YELLOW LED FOR PEDESTRIANS
	Timer0_Delay(5);

	ledToggle(PORTA_ID,PIN1_ID);
	ledToggle(PORTB_ID,PIN1_ID); // YELLOW LED FOR PEDESTRIANS
	Timer0_Delay(5);

	 Yellow_is_blinking = 0;
}
/*******************************************************************************
 * [Function Name] : PED_Mood
 *
 * [Description]   : Function to Change from normal mode to pedestrian mode when the
 *                    pedestrian button is pressed.
 *
 * [Args in]       : NONE
 * [Args out]      : NONE
 *******************************************************************************/
void PED_Mood ()
{
	    /*  FIRST CASE:
		 If BUTTON is pressed when the cars' Red LED is on
		 the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
		*/

	//BIT_IS_SET(PORTA_ID,PIN2_ID)
	   if (buttonClick==1)  // check if the button is pressed when the cars' RED LED is on
		 {
		   ledOff(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
		   Blinking_yellow ();
		   ledOff(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
		   ledOff(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
		   ledOff(PORTB_ID,PIN2_ID); // RED LED FOR PEDSTRAINS
		   ledOn(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
		   ledOn(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDSTRAINS
	     	 Timer0_Delay(20);

		 }

	    /*     SECOND CASE:
		      If BUTTON is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
		*/

	else if( BIT_IS_SET(PORTA_ID,PIN0_ID) ||   Yellow_is_blinking ==1){
		 // the pedestrian Red LED will be on
				 ledOff(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
				 ledOn(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS

		// then both Yellow LEDs start to blink for five seconds,
			    Blinking_yellow ();
			    ledOff(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
			    ledOff(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS
			    ledOff(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
		// then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
				 ledOn(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
				 ledOn(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS
				 Timer0_Delay(20);
	}

	// 	 At the end of the two states :
	// 	 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
	// 	 and the pedestrian's Green LED is still on

	        ledOff(PORTA_ID,PIN2_ID);  // RED LED FOR CARS
			Blinking_yellow ();
			ledOff(PORTA_ID,PIN1_ID);  // YELLOW LED FOR CARS
			ledOff(PORTB_ID,PIN1_ID);  // YELLOW LED FOR PEDESTRIANS

	//   After 5 seconds the pedestrian Green LED will be off
	//   and both the pedestrian Red LED and the cars' Green LED will be on.
		  ledOff(PORTB_ID,PIN0_ID);  // GREEN LED FOR PEDESTRIANS

		  ledOn(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
		  ledOn(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
		  Timer0_Delay(20);
		  ledOff(PORTA_ID,PIN0_ID);  // GREEN LED FOR CARS
		  ledOff(PORTB_ID,PIN2_ID);  // RED LED FOR PEDESTRIANS
		  app_start();

}

ISR (INT0_vect)
{
	PED_Mood();

}
