#include <msp430.h> 
#include "Lab4_helper.h";
/*
 * main.c
 */
int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initSPI();
	LCDinit();
	LCDclear();

	while (1) {
	}

	return 0;
}
