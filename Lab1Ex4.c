// Filename: Lab1Ex4.c
// Version: 1.0
// Date: <Insert current date>
// Author: <Insert your name>

//
// Description: A simple program to monitor a switch press and light up an LED
// using a PIC16f877A.
#include <xc.h> // Required by the XC8 compiler
void main(void)
{
// Make PORTD input and PORTB output
TRISD=0xFF; // Make PORTD input
TRISB=0x00; // Make PORTB output
while (1) // Infinite (endless) loop
{
if (RD0==1) // Has SW0 switch on PORTD been pressed?
{
PORTB=0xff; // Turn all PORTB LEDs ON
}
else
{
PORTB=0x00; // Otherwise switch all PORTB LEDs OFF
}
}
}
