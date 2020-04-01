/**
 * \file main.c
 *
 * \brief Main source file.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use this software and
    any derivatives exclusively with Microchip products. It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#pragma config WDTE = OFF   /* WDT operating mode->WDT Disabled */
#pragma config LVP = ON     /* Low voltage programming enabled, RE3 pin is MCLR */

#include <xc.h>

static void CLK_init(void);
static void PORT_init(void);

/* Clock initialization function */
static void CLK_init(void)
{
    /* set HFINTOSC Oscillator */
    OSCCON1bits.NOSC = 6;
    /* set HFFRQ to 1 MHz */
    OSCFRQbits.HFFRQ = 0;
}

/* PORT initialization function */
static void PORT_init(void)
{
    /* Set RE0 (LED) pin as output */
    TRISEbits.TRISE0 = 0;
    /* Set RE2 (button) pin as input*/
    TRISEbits.TRISE2 = 1;
    
    /* Enable weak pull-up for pin RE2 (button) */
    WPUEbits.WPUE2 = 1;
    
    /* Enable digital input buffer for pin RE2 (button) */ 
    ANSELEbits.ANSELE2 = 0;
}

void main(void) {
    
    CLK_init();
    PORT_init();
    
    while (1)
    {
        if(PORTEbits.RE2)     /* Read the input pin value */
        {
            LATEbits.LATE0 = 1;   /* Turn off LED */ 
        }
        else
        {
            LATEbits.LATE0 = 0;  /* Turn on LED */
        }
    }
}
