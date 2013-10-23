/*
 * Lab4_Helper.h
 *
 *  Created on: Oct 22, 2013
 *      Author: Administrator
 */

#ifndef LAB4_HELPER_H_
#define LAB4_HELPER_H_

void initSPI();

void LCDinit();

void LCDclear();

void cursorToLineTwo();

void cursorToLineOne();

void writeChar(char asciiChar);

void writeString(char * string);

void scrollString(char * string1, char * string2);

void writeDataByte(char dataByte);

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

void setSSHi();

void setSSLo();

void SPI_send(char byteToSend);

string decryptMessage(string message, char key);

char decryptSingle(char encryptedCharacter, char key);

int checkButtonPress(int buttonNumber);

void calibrateClock();

void LCD_write_8(char byteToSend);

void LCD_write_4(char byteToSend);

#endif /* LAB4_HELPER_H_ */
