

// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// SPI SLAVE PROGRAMME FOR LED ROTATION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _XTAL_FREQ 4000000
#include <xc.h>

void main() 
{
	RCREG=0X90;
  SSPSTAT=0X00;
SSPCON=0X25;
TRISC3=1;
TRISC4=1;
TRISC5=0;
TRISB=0X00;
while(1)
{
    while(SSPIF==0);
    RCREG=SSPBUF;
    SSPIF=0;
}
}
