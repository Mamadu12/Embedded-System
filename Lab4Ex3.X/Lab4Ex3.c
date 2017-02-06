// Filename: Lab4Ex2.c
// Version: 1.0
// Date:    <09/12/2016>
// Author: <Mamadu Balde>
//
// Description: Looping of a short timer delay to create a longer one  
#include <xc.h>             // Required for all MPLAB XC8 source files
void one_sec_delay (void);  //Function prototype
void main(void)
{
    // PORTD setup
    TRISD = 0x00;               // Set PORTD all outputs
    PORTD = 0x00;               // Clear PORTD
    while(1){
    one_sec_delay();
    PORTD++;

}
}

void one_sec_delay (void)
{
    unsigned char preload = 96;    // TMR0 preload variable
    unsigned char i;    
    //Timer0 setup
    OPTION_REGbits.T0CS = 0;    // Set clock source to internal (timer mode)
    OPTION_REGbits.PSA = 0;     // Set prescaler to Timer 0
    OPTION_REGbits.PS = 7;      // Set prescaler bits to 111 for 1:256
                            
    for(i=0;i<20;i++)       // Loop to cascade several short delays together
        {
            TMR0 = preload;             // Preload timer0
            while(!INTCONbits.TMR0IF);    // Delay loop: Wait until TMR0 overflows
            INTCONbits.TMR0IF = 0;        // Reset overflow flag, TMR0IF
        }
                       // Increment PORTD
    }

