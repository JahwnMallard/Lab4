Lab4 - LCD Driver
C2C John Miller

Implements LCD device drivers for the MSP 430
Takes in 3 messages and 3 keys, and based on button presses,
decrypts the message, scrolls "ECE382 is my favorite class" on the top line,
and the decrypted message on the bottom.

functions used: (descriptions will be added as the functions are created)



/*---------------------------------------------------
 Function Name: initButtons
 Author: C2C John Miller, USAF
 Function: Initializes bits 0, 1, and 2 as inputs for buttons
 Inputs: none
 Outputs: none
 Subroutines used: configureP1PinAsButton
 ---------------------------------------------------*/

void initButtons();

/*---------------------------------------------------
 Function Name: INITSPI
 Author: C2C John Miller, USAF
 Function: Initializes the SPI of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void initSPI();

/*---------------------------------------------------
 Function Name: LCDinit
 Author: Capt Todd Branchflower, USAF
 Function: Initializes the LCD screen of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void LCDinit();

/*---------------------------------------------------
 Function Name: initProgram
 Author: C2C John Miller, USAF
 Function: Initializes the program
 Inputs: none
 Outputs: none
 Subroutines used: LCDinit, initSPI, LCDclear, initButtons
 ---------------------------------------------------*/

void initProgram();
/*---------------------------------------------------
 Function Name: LCDclear
 Author: Capt Todd Branchflower, USAF
 Function: Clears the LCD screen of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void LCDclear();

/*---------------------------------------------------
 Function Name: cursorToLineTwo
 Author: C2C John Miller, USAF
 Function: set the cursor to the beginning of the bottom half of the LCD
 Inputs: none
 Outputs: none
 Subroutines used: cursorToLineOne, writeCommandByte
 ---------------------------------------------------*/
void cursorToLineTwo();

/*---------------------------------------------------
 Function Name: cursorToLineTwo
 Author: C2C John Miller, USAF
 Function: set the cursor to the beginning of the top half of the LCD
 Inputs: none
 Outputs: none
 Subroutines used: writeCommandByte
 ---------------------------------------------------*/
void cursorToLineOne();

/*---------------------------------------------------
 Function Name: writeChar
 Author: C2C John Miller, USAF
 Function: Writes a single character
 Inputs: asciiChar
 Outputs: none
 Subroutines used: writeCommandByte, writeDataByte
 ---------------------------------------------------*/
void writeChar(char asciiChar);

/*---------------------------------------------------
 Function Name: writeString
 Author: C2C John Miller, USAF
 Function: Writes a string of characters
 Inputs: string, length
 Outputs: none
 Subroutines used: writeChar
 ---------------------------------------------------*/
void writeString(char * string, int length);

/*---------------------------------------------------
 Function Name: scrollString
 Author: C2C John Miller, USAF
 Function: Scrolls a message across the top of the lcd screen.
 Inputs: string1, string2, message1Length
 Outputs: none
 Subroutines used: writeString
 ---------------------------------------------------*/
void scrollString(char * string1, char * string2, int message1Length,
		int message2Length);

/*---------------------------------------------------
 Function Name: SET_SS_HI
 Author: C2C John Miller, USAF
 Function: ; Sets slave select to high (disabled) on the LCD
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void set_SS_Hi();

/*---------------------------------------------------
 Function Name: SET_SS_LO
 Author: C2C John Miller, USAF
 Function: ; Sets slave select to low (enabled) on the LCD
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void set_SS_Lo();

/*---------------------------------------------------
 Subroutine Name: SPI_send
 Author: Capt Todd Branchflower, USAF
 Function: Send a byte to the SPI for either commands or data
 Outputs: none
 Subroutines used: set_SS_hi, set_SS_lo
 ---------------------------------------------------*/
void SPI_send(char byteToSend);

/*---------------------------------------------------
 Subroutine Name: calibrateClock
 Author: C2C John Miller, USAF
 Function: calibrates clock of the MSP430 to 1, 8 12  or 16 MHz
 Inputs:frequency (must be 1, 8, 12, or 16)
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void calibrateClock(char frequency);

/*---------------------------------------------------
 Subroutine Name: LCD_write_8
 Author: Capt Todd Branchflower, USAF
 Function: Send full byte to LCD
 Inputs: byteToSend
 Outputs: none
 Subroutines used: LCD_write_4
 ---------------------------------------------------*/
void LCD_write_8(char byteToSend);

/*---------------------------------------------------
 Subroutine Name: LCD_write_4
 Author: C2C John Miller, USAF
 Function: Send 4 bits of data to LCD via SPI.
 sets upper four bits to match LCDCON.
 Inputs: byteToSend
 Outputs: none
 Subroutines used: LCD_write_4
 ---------------------------------------------------*/
void LCD_write_4(unsigned char byteToSend);

/*---------------------------------------------------
 Function Name: delayMicro
 Author: C2C John Miller, USAF
 Function: Delays the MSP430 by 40.5 microseconds
 Inputs: none
 Outputs: none
 Subroutines used: __delay_cycles()
 ---------------------------------------------------*/
void delayMicro();

/*---------------------------------------------------
 Function Name: delayMilli
 Author: C2C John Miller, USAF
 Function: Delays the MSP430 by 1.65 milliseconds
 Inputs: none
 Outputs: none
 Subroutines used: __delay_cycles()
 ---------------------------------------------------*/
void delayMilli();
