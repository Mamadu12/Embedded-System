//Filename: Lab5Ex1.c
// Version: 1.0
// Date: <09/12/2016>
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
// Interrupt service routine
void interrupt myISR(void)
{
if(TMR0IF) // Timer0 overflow interrupt specific code
{
PORTD++;
INTCONbits.TMR0IF = 0; // Reset flag
}
}
