#include <msp430.h> 
#include "Lab4_helper.h";
/*
 * main.c
 */

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	char MESSAGE[]={'T', 'E', 'S', 'T', ' ', ' ', ' ', ' '};
	char * messagePointer = &MESSAGE[0];
	initSPI();
	LCDinit();
	LCDclear();
	writeString( messagePointer);


	while (1) {
	}

	return 0;
}
