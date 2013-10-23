Lab4 - LCD Driver
C2C John Miller

Implements LCD device drivers for the MSP 430
Takes in 3 messages and 3 keys, and based on button presses,
decrypts the message, scrolls "ECE382 is my favorite class" on the top line,
and the decrypted message on the bottom.

functions used: (descriptions will be added later)
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