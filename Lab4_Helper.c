/*
 /*
 * Author: C2C John Miller
 * Lab4 - Implementation of LCD Driver functions
 *
 *  Created on: Oct 22, 2013
 *      Author: Administrator
 */
#include <msp430.h>;
#include "Lab4_helper.h";
#define RS_MASK 0x40
char LCDCON;

void writeDataByte(char dataByte);

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

void initSPI()

{
	UCB0CTL1 |= UCSWRST;
	UCB0CTL0 |= UCCKPL | UCMSB | UCMST | UCSYNC;

	UCB0CTL1 |= UCSSEL1; //Selects which clock to use
	UCB0STAT |= UCLISTEN; //enables internal loopback

	P1DIR |= BIT4; //P1.4 is used as the slave select

	P1SEL |= BIT6; //make UCB0SSOMI available on P1.6
	P1SEL2 |= BIT6;

	P1SEL |= BIT5; //make UCB0CLK available on P1.5
	P1SEL2 |= BIT5;

	P1SEL |= BIT7; //make UCB0SSIMO available on P1.7
	P1SEL2 |= BIT7;

	UCB0CTL1 &= ~UCSWRST; //enable subsystem

}

void LCDclear() {
	writeCommandByte(1);
}

void LCDinit() {
	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

	writeCommandNibble(0x03);

	writeCommandNibble(0x02);

	writeCommandByte(0x28);

	writeCommandByte(0x0C);

	writeCommandByte(0x01);

	writeCommandByte(0x06);

	writeCommandByte(0x01);

	writeCommandByte(0x02);

	SPI_send(0);
	delayMicro();
}

void writeCommandNibble(char commandNibble) {
	LCDCON &= ~RS_MASK;
	LCD_write_4(commandNibble);
	delayMilli();
}

void writeCommandByte(char commandByte) {
	LCDCON &= ~RS_MASK;
	LCD_write_8(commandByte);
	delayMilli();
}

void writeDataByte(char dataByte) {
	LCDCON |= RS_MASK;
	LCD_write_8(dataByte);
	delayMilli();
}

void LCD_write_8(char byteToSend) {
	unsigned char sendByte = byteToSend;

	sendByte &= 0xF0;

	sendByte = sendByte >> 4;               // rotate to the right 4 times

	LCD_write_4(sendByte);

	sendByte = byteToSend;

	sendByte &= 0x0F;

	LCD_write_4(sendByte);
}

void LCD_write_4(unsigned char sendByte) {
	sendByte &= 0x0F;

	sendByte |= LCDCON;

	sendByte &= 0x7F;

	SPI_send(sendByte);

	delayMicro();

	sendByte |= 0x80;

	SPI_send(sendByte);

	delayMicro();

	sendByte &= 0x7F;

	SPI_send(sendByte);

	delayMicro();

}

void set_SS_hi() {
	P1OUT |= BIT4;  //Disables slave select
}

void set_SS_lo() {
	P1OUT &= ~BIT4;  //Enables slave select
}

void SPI_send(char byteToSend) {
	char readByte;

	set_SS_lo();

	UCB0TXBUF = byteToSend;

	while (!(UCB0RXIFG & IFG2)) {
		// wait until you've received a byte
	}

	readByte = UCB0RXBUF;

	set_SS_hi();
}

void delayMicro() {
	__delay_cycles(43);
}

void delayMilli() {
	__delay_cycles(1743);
}
