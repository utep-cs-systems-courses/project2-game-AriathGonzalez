//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_RED;  // Turn off red led
  P1OUT |= LED_GREEN;  // Turn on green led

  or_sr(0x18);		/* CPU off, GIE on */
}