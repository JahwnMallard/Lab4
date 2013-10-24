/*
 * Lab4_Helper.h
 *
 *  Created on: Oct 22, 2013
 *      Author: Administrator
 */

#ifndef LAB4_HELPER_H_
#define LAB4_HELPER_H_

/*
 Function Name: INITSPI
 Author: C2C John Miller, USAF
 Function: Initializes the SPI of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 */
void initSPI();

/*
 Function Name: LCDinit
 Author: Capt Todd Branchflower, USAF
 Function: Initializes the LCD screen of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 */
void LCDinit();

/*
 Function Name: LCDclear
 Author: Capt Todd Branchflower, USAF
 Function: Clears the LCD screen of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 */
void LCDclear();

void cursorToLineTwo();

void cursorToLineOne();

void writeChar(char asciiChar);

void writeString(char * string);

void scrollString(char * string1, char * string2);

void writeDataByte(char dataByte);

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

/*
 Function Name: SET_SS_HI
 Author: C2C John Miller, USAF
 Function: ; Sets slave select to high (disabled) on the LCD
 Inputs: none
 Outputs: none
 Subroutines used: none
 */
void set_SS_Hi();

/*
 Function Name: SET_SS_LO
 Author: C2C John Miller, USAF
 Function: ; Sets slave select to low (enabled) on the LCD
 Inputs: none
 Outputs: none
 Subroutines used: none
 */
void set_SS_Lo();

void SPI_send(char byteToSend);

int checkButtonPress(int buttonNumber);

void calibrateClock();

void LCD_write_8(char byteToSend);

void LCD_write_4(char byteToSend);

/*
 Function Name: delayMicro
 Author: C2C John Miller, USAF
 Function: Delays the MSP430 by a microsecond
 Inputs: none
 Outputs: none
 Subroutines used: __delay_cycles()
 */
void delayMicro();

/*
 Function Name: delayMilli
 Author: C2C John Miller, USAF
 Function: Delays the MSP430 by a millisecond
 Inputs: none
 Outputs: none
 Subroutines used: __delay_cycles()
 */
void delayMilli();


#endif /* LAB4_HELPER_H_ */
