#include <msp430.h> 
//#include <driverlib.h>
//#include "StopWatchMode.h"
//#include "TempSensorMode.h"
#include "hal_LCD.h"


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    //displayScrollText("WELCOME TO THE FR6989 LAUNCHPAD");
	while(1){
	    //printf("hello");
	    Init_LCD();
	    displayScrollText("AAAAAAAAAAA");

	}
	//clearLCD();

	return 0;
}