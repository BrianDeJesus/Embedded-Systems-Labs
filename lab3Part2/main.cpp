/*----------------------------------------------------------------------------
LAB EXERCISE - DIGITAL INPUTS AND OUTPUTS
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
	1) Define BusIn, BusOut interfaces for inputs and outputs
	2) The RGB LED is controlled by the buttons:
			+ Button 1 - light RED
			+ Button 2 - light BLUE
			+ Button 3 - light GREEN
			+ Button 4 - light WHITE (RED, GREEN and BLUE at the same time)
			
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

//Define input bus
	//Write your code here
  DigitalIn button1(PA_10);
	DigitalIn button2(PB_3);
	DigitalIn button3(PB_5);
	DigitalIn button4(PB_4);
	
//Define output bus for the RGB LED
	//Write your code here
	DigitalOut red(PB_10);
	DigitalOut blue(PA_9);
	DigitalOut green(PA_8);

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

void delay(float time){// delay function 
	volatile int i;
	for(i=0; i<1000000*time; i++);
}

int main(){
	
	  red = 0; //intialize 
		blue = 0;
		green = 0;
	
		int count = 0;
	
	while(1){
		//Check which button was pressed and light up the corresponding LEDs
		//Write your code here
		
		if(!button1){
			red = !red;
			count += 1;
			delay(1);
		}
		if(!button2){
			blue = !blue;
			count += 1;
			delay(1);
		}
		if(!button3){
			green = !green;
			count += 1;
			delay(1);
		}
		if(!button4){
			green = !green;
			blue = !blue;
			red = !red;
			count += 1;
			delay(1);
		}
		
		if(count >= 10){
			green = 1;		//If button was pressed 10 times, light the green led up
		}
		
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2016*************************************
