
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 4000000

void main() 
{
    char a;
    int i;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=25;
    SSPSTAT=0X80;
    SSPCON=0X20;
    TRISC3=0;
    TRISC4=1;
    TRISC5=0;
    
    while(1)
    {
        while(RCIF==0);
        a=RCREG;
        TXREG=a;
        while(TRMT==0);
        SSPBUF=a;
        while(SSPIF==0);
    }
}

 