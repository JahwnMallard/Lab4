#include <msp430.h> 
#include "Lab4_helper.h";
#include "button.h";
/*
 * main.c
 */

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	char * mainMessage = "ECE382 is my favorite class! ";
	char * initialMessageTop = "Message?";
	char * initialMessageBottom = "Press123";

	char * message1 = "Documentation: Some ";
	char * message2 = "ASCII isn't sufficient for this message ";
	char * message3 = "I put the sin in 'syntax error' ";

	int mainMessageLength = 29;
	int message1Length = 20;
	int message2Length = 40;
	int message3Length = 32;

	char * selection;
	int selectionLength;

	calibrateClock(1);
	initProgram();
	char buttons[] = { BIT0, BIT1, BIT2 };

	writeString(initialMessageTop, LCD_WIDTH);
	cursorToLineTwo();
	writeString(initialMessageBottom, LCD_WIDTH);

	char option = pollP1Buttons(buttons, 3);



	switch (option) {
	case BIT0:
		selection = message1;
		selectionLength = message1Length;
		break;

	case BIT1:
		selection = message2;
		selectionLength = message2Length;
		break;

	case BIT2:
		selection = message3;
		selectionLength = message3Length;
		break;
	}

	while (1) {
		scrollString(mainMessage, selection, mainMessageLength,
				selectionLength);
	}
	return 0;
}
