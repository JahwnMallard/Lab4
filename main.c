#include <msp430.h> 
#include "Lab4_helper.h";
/*
 * main.c
 */

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	char mainMESSAGE[] = { 'E', 'C', 'E', '3', '8', '2', ' ', 'i', 's', ' ',
			'm', 'y', ' ', 'f', 'a', 'v', 'o', 'r', 'i', 't', 'e', ' ', 'c',
			'l', 'a', 's', 's', '!', ' ' };
	int mainMessageLength = 30;
	char * mainMessagePointer = &mainMESSAGE[0];
	initSPI();
	LCDinit();
	LCDclear();
//	while (1) {
//		scrollString(mainMessagePointer, mainMessagePointer, mainMessageLength);
//	}
	char test[] = { 't', 'e', 's', 't' };
	char test2[] = { 'y', 'e', 'a', 'h' };
	char *test1Pointer = &test[0];
	char *test2Pointer = &test2[0];
	writeString(test1Pointer, 4);
	cursorToLineTwo();
	writeString(test2Pointer, 4);

	return 0;
}
