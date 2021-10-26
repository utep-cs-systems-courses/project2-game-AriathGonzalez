//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;  // Green off
  P1OUT &= ~LED_RED;
  //P1OUT |= LED_RED;  // Red On

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state var to count time
int secondCount = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  secondCount ++;
  if (secondCount >= 125) { 	/* once each sec... */
    P1OUT &= ~LED_RED;
    P1OUT ^= LED_GREEN;		/* toggle green LED */
  }
  if (secondCount >= 250){
    secondCount = 0;  // Reset count
    P1OUT &= ~LED_GREEN;  // Turn off green
    P1OUT ^= LED_RED;
  }
}

