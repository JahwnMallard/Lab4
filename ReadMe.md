Lab4 - LCD Driver
C2C John Miller

Implements LCD device drivers for the MSP 430
Takes in 3 messages and 3 keys, and based on button presses,
decrypts the message, scrolls "ECE382 is my favorite class" on the top line,
and the decrypted message on the bottom.

functions used: (descriptions will be added as the functions are created)



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
 Function Name: LCDclear
 Author: Capt Todd Branchflower, USAF
 Function: Clears the LCD screen of the MSP430
 Inputs: none
 Outputs: none
 Subroutines used: none
 ---------------------------------------------------*/
void LCDclear();

void cursorToLineTwo();

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
 Inputs: string
 Outputs: none
 Subroutines used: writeChar
 ---------------------------------------------------*/
void writeString(char * string);

void scrollString(char * string1, char * string2);

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

int checkButtonPress(int buttonNumber);

void calibrateClock();

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