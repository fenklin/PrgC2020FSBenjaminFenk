#include "main.h"
#include "hal_LCD_complete.h"

volatile unsigned char s1current, s2current;
volatile unsigned char s1last, s2last;

void batLvlDisp (int);

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                  // Stop WDT

    PM5CTL0 &= ~LOCKLPM5;                      // Disable the GPIO power-on default high-impedance mode
                                               // to activate previously configured port settings
    Init_LCD();

    displayScrollText("PRG_C BENJAMIN FENK");
    displayScrollText("PRG_C BENJAMIN FENK");

    // initialize battery display [    ]|
    LCDM12 = 0x10;
    LCDM13 = 0X01;

    int batLvl = 0;

    // handles button presses
    P1DIR |= BIT0;                             // P1.0 pin set as output the rest are input
    P4DIR |= BIT0;                             // P4.0 pin set as output the rest are input

    P2REN |= BIT6;                             // Enable internal pull-up/down resistors for P2.6
    P2OUT |= BIT6;                             // Select pull-up mode for P2.6
    P1REN |= BIT2;                             // Enable internal pull-up/down resistors for P1.2
    P1OUT |= BIT2;                             // Select pull-up mode for P1.2

    while(1)
    {
        if ((P1IN & BIT2) != BIT2)             // Button 1 is pressed
        {
            P1OUT ^=BIT0;
            if (batLvl > 0)
            {
                batLvl--;
                batLvlDisp(batLvl);
                __delay_cycles(300000);
            }
        }

        if (P1IN & BIT2)                       // Button 1 is released
        {
            P1OUT &= ~BIT0;
        }


        if ((P2IN & BIT6) != BIT6)             // Button 2 is pressed
        {
            P4OUT ^=BIT0;
            if (batLvl < 6)
            {
                batLvl++;
                batLvlDisp(batLvl);
                __delay_cycles(300000);
            }
        }

        if (P2IN & BIT6)                       // Button 2 is released
        {
            P4OUT &= ~BIT0;
        }
    }
}

void batLvlDisp (batLvl)
{
switch (batLvl)
   {
       case 0:
       //level 0
       LCDM12 = 0x10;
       LCDM13 = 0x01;
       return;

       case 1:
       //level 1
       LCDM12 = 0x10;
       LCDM13 = 0x03;
       return;

       case 2:
       //level 2
       LCDM12 = 0x30;
       LCDM13 = 0x03;
       return;

       case 3:
       //level 3
       LCDM12 = 0x30;
       LCDM13 = 0x07;
       return;

       case 4:
       //level 4
       LCDM12 = 0x70;
       LCDM13 = 0x07;
       return;

       case 5:
       //level 5
       LCDM12 = 0x70;
       LCDM13 = 0x0f;
       return;

       case 6:
       //level 6
       LCDM12 = 0xf0;
       LCDM13 = 0x0f;
       return;
   }
}
