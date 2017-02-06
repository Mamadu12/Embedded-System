// Filename: Lab5Ex2.c
// Version: 1.0
// Date: <10/12/2016>
// Author: <Mamadu Balde>
//
// Description: Implementing a Timer0 overflow interrupt
#include <xc.h> // Required for all MPLAB XC8 source files
void main(void)
{
TRISD = 0x00; // Set up ports
PORTD = 0x00;
INTCON = 0xA0; // SET GIE, TMR0IE
// Set up Timer0 for 80 ms per overflow
OPTION_REGbits.T0CS = 0; // Set clock source to internal (timer mode)
OPTION_REGbits.PSA = 0; // Set prescaler to Timer 0
OPTION_REGbits.PS = 7; // Set prescaler bits to 111 for 1:256
while(1); // Do nothing
}
void interrupt myISR(void){
    if(TMR0IF){
        TMR0=156;// count from 156 to 255 and 100 incrementations per interrupt
        static int i;
        i++;
    if(i==32){// it needs 32 interrupts for 1s
        PORTD++; // increment PORTD is incremented after 32 interrups
        // with 100 counts
        i=0;
    }T0IF=0;// clear TIMER0 interrupt flag bit
    }
}