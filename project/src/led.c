#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;   // Bits attached to leds are output
  // switch_state_changed = 1;
  led_update();
}

void led_update()
{
  // LEDS start off
  P1OUT &= ~LEDS;
}

void redOn(int on)
{
  // 1 for on, 0 for off
  switch(on){
  case 0:
    P1OUT &= ~LED_RED;
    break;
  case 1:
    P1OUT |= LED_RED;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void greenOn(int on)
{
  // 1 for on, 0 for off
  switch(on){
  case 0:
    P1OUT &= ~LED_GREEN;
    break;
  case 1:
    P1OUT |= LED_GREEN;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void ledsOn(int on)
{
  // 1 for on, 0 for off
  switch(on){
  case 0:
    P1OUT &= ~LEDS;
    break;
  case 1:
    P1OUT |= LEDS;
    break;
  default:
    P1OUT |= LEDS;
    break;
  }
}

void altLEDS(int on)
{
  // 1 - Red on, Green off
  // 0 - Green on, Red off
  switch(on){
  case 0:
    redOn(1);
    greenOn(0);
    break;
  case 1:
    redOn(0);
    greenOn(1);
    break;
  default:
    ledsOn(0);
    break;
  }
}

