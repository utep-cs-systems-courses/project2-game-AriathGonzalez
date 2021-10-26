#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "notes.h"

static int toggleRed = 0;
static int toggleGreen = 0;

void redDim25()
{
  switch (toggleRed){
  case 0:
    redOn(0);
    toggleRed = 1;
  case 1:
    toggleRed = 2;
  case 2:
    toggleRed = 3;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
    break;
  default:
    break;
  }
}

void redDim50()
{
  switch (toggleRed){
  case 0:
    redOn(1);
    toggleRed = 1;
    break;
  case 1:
    redOn(0);
    toggleRed = 2;
    break;
  case 2:
    toggleRed = 3;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
  default:
    break;
  }
}

void redDim75()
{
  switch(toggleRed){
  case 0:
    redOn(0);
    toggleRed = 1;
    break;
  case 1:
    toggleRed = 2;
    break;
  case 2:
    toggleRed = 3;
    break;
  case 3:
    redOn(1);
    toggleRed = 0;
    break;
  default:
    break;
  }
}
void greenDim25()
{
  switch (toggleGreen){
  case 0:
    greenOn(0);
    toggleGreen = 1;
  case 1:
    toggleGreen = 2;
  case 2:
    toggleGreen = 3;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
    break;
  default:
    break;
  }
}

void greenDim50()
{
  switch (toggleGreen){
  case 0:
    greenOn(1);
    toggleGreen = 1;
    break;
  case 1:
    greenOn(0);
    toggleGreen = 2;
    break;
  case 2:
    toggleGreen = 3;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
  default:
    break;
  }
}

void greenDim75()
{
  switch(toggleGreen){
  case 0:
    greenOn(0);
    toggleGreen = 1;
    break;
  case 1:
    toggleGreen = 2;
    break;
  case 2:
    toggleGreen = 3;
    break;
  case 3:
    greenOn(1);
    toggleGreen = 0;
    break;
  default:
    break;
  }
}

void dim_sequence()
{
  static int dimState = 0;

  switch (dimState){
  case 0:
    redDim75();
    greenDim25();
    dimState = 1;
    break;
  case 1:
    redDim25();
    greenDim75();
    dimState = 2;
    break;
  case 2:
    redDim50();
    greenDim50();
    dimState = 0;
    break;
  default:
    break;
  }
}

// Try with an array instead
void playSong()
{
  static char currNote = 0;
  int notes[15] = {GSHARP, GSHARP, 0, B, B, 0, ASHARP, ASHARP, ASHARP, A, 0, E, 0, DSHARP, 0};
  int n = 15;

  // If oddPress, play song, otherwise, don't play anything
  if (oddPress1 = 1){
    // To go through array of notes
    if (currNote < n){
      buzzer_set_period(notes[currNote]);
      currNote++;
    }
    else{
      currNote = 0;
    }
  }
  else{
    buzzer_set_period(0);
    currNote = 0;
  }
      
  /*
  switch(currNote) {
  case 0:
    buzzer_set_period(GSHARP);
    altLEDS(1);
    currNote++;
    break;
  case 2:
    buzzer_set_period(0);
    ledsOn(0);
    currNote++;
    break;
  case 3:
    buzzer_set_period(B);
    altLEDS(0);
    currNote++;
    break;
  case 5:
    buzzer_set_period(0);
    ledsOn(0);
    currNote++;
    break;
  case 6:
    buzzer_set_period(ASHARP);
    altLEDS(1);
    currNote++;
    break;
  case 9:
    buzzer_set_period(A);
    altLEDS(0);
    currNote++;
    break;
  case 10:
    buzzer_set_period(0);
    ledsOn(0);
    currNote++;
    break;
  case 11:
    buzzer_set_period(E);
    altLEDS(1);
    currNote++;
    break;
  case 12:
    buzzer_set_period(0);
    ledsOn(0);
    currNote++;
    break;
  case 13:
    buzzer_set_period(DSHARP);
    altLEDS(0);
    currNote++;
    break;
  case 14:
    buzzer_set_period(0);
    ledsOn(0);
    currNote = 0;
    break;
  default:
    currNote++;
    }*/

}

void playSong2()
{
  static char currNote = 0;

  if (oddPress2 = 1){
    switch(currNote){
    case 0:
      buzzer_set_period(CSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 1:
      buzzer_set_period(FSHARP);
      altLEDS(0);
      currNote++;
      break;
    case 2:
      buzzer_set_period(GSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 3:
      buzzer_set_period(A);
      altLEDS(0);
      currNote++;
      break;
    case 5:
      buzzer_set_period(CSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 7:
      buzzer_set_period(FSHARP);
      altLEDS(0);
      currNote++;
      break;
    case 8:
      buzzer_set_period(GSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 10:
      buzzer_set_period(A);
      altLEDS(0);
      currNote++;
      break;
    case 14:
      buzzer_set_period(D);
      altLEDS(1);
      currNote++;
      break;
    case 15:
      buzzer_set_period(FSHARP);
      altLEDS(0);
      currNote++;
      break;
    case 16:
      buzzer_set_period(GSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 18:
      buzzer_set_period(D);
      altLEDS(0);
      currNote++;
      break;
    case 20:
      buzzer_set_period(FSHARP);
      altLEDS(1);
      currNote++;
      break;
    case 21:
      buzzer_set_period(GSHARP);
      altLEDS(0);
      currNote++;
      break;
    case 22:
      buzzer_set_period(A);
      altLEDS(1);
      currNote++;
      break;
    case 26:
      buzzer_set_period(0);
      ledsOn(0);
      currNote = 0;
      break;
    default:
      currNote++;
      break;
   }
  }
  else {
    buzzer_set_period(0);
    currNote = 0;
  }
}

void playSong3()
{
  static char currNote = 0;
  int notes[28] = {C, A, C, 0, B, 0, C, B, 0, G, G, G, 0, A, E, D, 0, C, 0, B, 0, C, B, 0, G, G, G,                   0};
  int n = 28;

  if (currNote < n){
      buzzer_set_period(notes[currNote]);
      currNote++;
  }
  else {
    currNote = 0;
  }
  
}
