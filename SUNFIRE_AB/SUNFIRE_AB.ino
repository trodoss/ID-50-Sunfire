/*
Sunfire - Space Flight Simulator/Shooter

2017 - Trodoss
*/

//determine the game
#define GAME_ID 50

#include "globals.h"
#include "menu.h"
#include "game.h"
#include "sound_data.h"

typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateGamePlaying,
};


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(30);                                 // set the frame rate of the game at 30 fps
  arduboy.initRandomSeed();                                 // This sets the random to more random, remove this if no random is needed !
  ATM.play(themeSong);
}


void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  arduboy.clear();
((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
  arduboy.display();
  if (arduboy.everyXFrames(3)) blinking = !blinking;
}

