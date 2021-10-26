//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_RED;
  P1OUT |= LED_GREEN;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}

// Global state var to count time
int secondCount = 0;

void __interrupt_vec(WDT_VECTOR) WDT ()
{
  secondCount ++;

  // Reset cycle
  if (secondCount >= 1000){  // 4 seconds have passed
    secondCount = 0;
    P1OUT &= ~LED_GREEN;
    P1OUT &= ~LED_RED;
  }
  else if (secondCount >= 750){
    // Turn Both lights on - 11
    P1OUT |= LED_GREEN;
    P1OUT |= LED_RED;
  }
  else if (secondCount >= 500){
    // Turn Red on, Green off - 10
    P1OUT &= ~LED_GREEN;
    P1OUT |= LED_RED;
  }
  else if (secondCount >= 250){
    // Turn Red off, Green on - 01
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
  }
}
