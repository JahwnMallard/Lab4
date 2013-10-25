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
	writeChar(0x73);
	writeChar(0x41);
	while (1) {
	}

	return 0;
}
