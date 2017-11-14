#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "elements.h"

char hand_state = 1;

#define V_CENTER 32 
#define H_CENTER 64

char backSectionY[16];
char pitch = 0;
char roll = 0;

void set_background_pitch() {
  char offset = pitch;
  offset += 6;
  for (char i=0; i< 16; i++) {
    backSectionY[i] = pgm_read_byte_near (PITCH_DATA + (offset * 16) + i);
  }
}

void set_background_roll() {
   for (char i=0; i< 16; i++) { 
     backSectionY[i] += roll;
   }
}

//8 * 32 sections
void draw_background_section (unsigned char strip, char y) {
  unsigned char start = (strip * 4);

  for (char i=0; i< 4; i++) {
    sprites.drawOverwrite((strip * 8), y + (i*8), IMG_BACKDROP, start+i);
  }
}

void stateGamePlaying() {
 gameState = STATE_GAME_PLAYING;

// arduboy.drawPixel(H_CENTER,V_CENTER,WHITE);

 hand_state = 1;
 if (arduboy.pressed(RIGHT_BUTTON)) {
  hand_state = 2;
  if (pitch < 6) pitch++;
 }
 
 if (arduboy.pressed(LEFT_BUTTON)) {
  hand_state = 0;
  if (pitch > -6)  pitch--;
 }
 
 if (arduboy.pressed(DOWN_BUTTON)) {
  hand_state = 3;
   if (roll > -8) roll--;
 }
 if (arduboy.pressed(UP_BUTTON)) {
  hand_state = 4;
   if (roll < 16) roll++;
 }

 if (arduboy.pressed(B_BUTTON)) {
   LevelElement bullet = level_element_get(0);
   
   if (bullet.state == STATE_HIDDEN) {
    bullet.state = BULLET_L_MOVE;
    bullet.x = 32;
    bullet.y = 32;
    level_element_update(0, bullet);

    bullet = level_element_get(1);
    bullet.state = BULLET_R_MOVE;
    bullet.x = 96;
    bullet.y = 32;
    level_element_update(1, bullet);   
   }
 }
 
  set_background_pitch();
  set_background_roll();
  for (char i=0; i< 16; i++) draw_background_section (i, backSectionY[i]); 
  level_element_handle(pitch, roll);

 sprites.drawSelfMasked(48,18, IMG_HUD, 0);
 sprites.drawSelfMasked(80,18, IMG_HUD, 1);
 sprites.drawSelfMasked(48,34, IMG_HUD, 2);
 sprites.drawSelfMasked(80,34, IMG_HUD, 3);
 sprites.drawSelfMasked(63,25, IMG_HUD, 4);

 sprites.drawOverwrite(0, 43, IMG_COCKPIT, 0);
 sprites.drawOverwrite(56, 48, IMG_HAND, hand_state);

 if (danger) {
   if (blinking) {
    sprites.drawOverwrite(12, 54, IMG_DANGER, 0);
   } else {
    sprites.drawOverwrite(12, 54, IMG_DANGER, 1);
   }
 }
 
};

void stateMenuPlay()
{
  //bullets
  level_element_add(TYPE_BULLET,0,0,STATE_HIDDEN, 2,0);
  level_element_add(TYPE_BULLET,0,0,STATE_HIDDEN, 2,0);
  //missle
  level_element_add(TYPE_MISSILE,0,0,STATE_HIDDEN, 2,0);
  //debris animation
  level_element_add(TYPE_DEBRIS, H_CENTER, V_CENTER, STATE_DEBRIS_TL_MOVE, 2, 0);
  //enemies
  level_element_add(TYPE_ENEMY_REAR, 0, 0, STATE_ENEMY_REAR_IN_TL, 1, 0);
  level_element_add(TYPE_ENEMY_FRONT, 32, 18, STATE_ENEMY_FRONT_IN_LF, 1, 0);
  //background
  for (char i=0; i< 16; i++) backSectionY[i] = 8;
  
  stateGamePlaying();
 
};



//-----------

#endif
