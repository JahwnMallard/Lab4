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


	char initialMessageTop[] = { 'M', 'e', 's', 's', ' a', 'g', 'e','?' };
	char * initialMessageTopPointer = &initialMessageTop[0];

	char initialMessageBottom[] = { 'P', 'r', 'e', 's', 's', '1', '2', ' 3' };
	char * initialMessageBottomPointer = &initialMessageBottom[0];


	initSPI();
	LCDinit();
	LCDclear();

	writeString(initialMessageTopPointer, LCD_WIDTH);
	cursorToLineTwo();
	writeString(initialMessageBottomPointer, LCD_WIDTH);
//	while (1) {
//		scrollString(mainMessagePointer, mainMessagePointer, mainMessageLength);
//	}

	return 0;
}
