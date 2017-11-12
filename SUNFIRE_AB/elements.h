#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "globals.h"

#define STATE_HIDDEN 0

#define TYPE_DEBRIS  0
#define TYPE_BULLET  1
#define TYPE_MISSILE 2

#define TYPE_ENEMY_REAR  10
#define TYPE_ENEMY_FRONT 11

#define STATE_DEBRIS_TL_MOVE 1
#define STATE_DEBRIS_TR_MOVE 2
#define STATE_DEBRIS_BL_MOVE 3
#define STATE_DEBRIS_BR_MOVE 4

#define STATE_ENEMY_REAR_IN_TL 10
#define STATE_ENEMY_REAR_IN_TR 11
#define STATE_ENEMY_REAR_IN_TM 12
#define STATE_ENEMY_REAR_IN_ML 13
#define STATE_ENEMY_REAR_IN_MR 14
#define STATE_ENEMY_REAR_IN_BL 15
#define STATE_ENEMY_REAR_IN_BM 16
#define STATE_ENEMY_REAR_IN_BR 17

#define STATE_ENEMY_REAR_OUT_TL 18
#define STATE_ENEMY_REAR_OUT_TR 19
#define STATE_ENEMY_REAR_OUT_TM 20
#define STATE_ENEMY_REAR_OUT_ML 21
#define STATE_ENEMY_REAR_OUT_MR 22
#define STATE_ENEMY_REAR_OUT_BL 23
#define STATE_ENEMY_REAR_OUT_BM 24
#define STATE_ENEMY_REAR_OUT_BR 25

#define STATE_ENEMY_FRONT_IN_LF   26
#define STATE_ENEMY_FRONT_IN_RT   27
#define STATE_ENEMY_FRONT_LF      28
#define STATE_ENEMY_FRONT_RT      29
#define STATE_ENEMY_FRONT_BANK_LF 30
#define STATE_ENEMY_FRONT_BANK_RT 31      

#define STATE_MISSILE_LAUNCH 50
#define STATE_MISSILE_CLOSE  51

#define BULLET_L_MOVE 80
#define BULLET_R_MOVE 81

#define STATE_EXPLODING 99

#define STEP_LENGTH  2
#define COUNTER_START    32


#define MAX_ELEMENT_RECORDS 12

struct LevelElement
{
  unsigned char id;          //elment identifier
  unsigned char type;        //element type
  unsigned char x;           // y position
  unsigned char y;           // x position
  unsigned char state;       //determines the state of the the element
  unsigned char speed;       //deternimes how fast the object moves
  unsigned char step;        //used to maintain animation step
  unsigned char counter;     //used for timed events
  unsigned char speed_counter;
  unsigned char life;        //used to determine how much damage the element can take
};

LevelElement levelElements[MAX_ELEMENT_RECORDS];
char element_count = 0;

void level_element_add(char type, char x, char y, char state, char speed, char life)
{
      levelElements[element_count].id = element_count;
      levelElements[element_count].type = type;
      levelElements[element_count].x = x;
      levelElements[element_count].y = y;
      levelElements[element_count].step = 0;
      levelElements[element_count].state = state;
      levelElements[element_count].counter = COUNTER_START;
      levelElements[element_count].speed = speed;
      levelElements[element_count].speed_counter = 0;
      levelElements[element_count].life = life;
      element_count++;  
}

LevelElement level_element_get(char id) {
  return levelElements[id];
}

level_element_update(char id, LevelElement element) {
  levelElements[id] = element;
}

bool level_test_element (LevelElement element, char testX, char testY)
{
   if (element.type < 2) return false;
   
   if ((element.y + 16) < testY) return false;
   if (element.y > (testY + 16)) return false;
   if ((element.x + 16) < testX) return false;
   if (element.x > (testX + 16)) return false;
   return true;
}

LevelElement bullet_move(LevelElement element) {
    element.step = 0;
    if (element.state > STATE_HIDDEN)
    {
       element.y -=1;
       switch (element.state)
       {
          case BULLET_L_MOVE:
          if (element.x < 64) {
            if (element.x > 32) element.step = 1;
            if (element.x > 48) element.step = 2;
            element.x +=4;
          } else {
            element.state = STATE_HIDDEN;
          }
          break;
          
          case BULLET_R_MOVE:
          if (element.x > 64) {
            if (element.x < 96) element.step = 1;
            if (element.x < 80) element.step = 2;
            element.x -=4;
          } else {
            element.state = STATE_HIDDEN;
          }
          break;
       }
    }

    if (element.state > STATE_HIDDEN)  sprites.drawSelfMasked(element.x, element.y, IMG_BULLET, element.step);
    return element;
}

//Debris handling
LevelElement debris_move(LevelElement element)
{
    bool newDebris = false;
       
    if (element.state > STATE_HIDDEN)
    {
      if (element.speed_counter == element.speed)
      {         
         if (element.counter > 0) {
             element.counter--;
        } else {
             element.counter = COUNTER_START;
        }
    
        element.speed_counter = 0;
          switch (element.state)
          {
            case STATE_DEBRIS_TR_MOVE:
            element.x+= 2;
            if (element.y > 2) {
               element.y -=2;
               element.step = 0;
               if (element.y < 24) element.step = 1;
               if (element.y < 16) element.step = 2;        
               if (element.y < 8) element.step = 3;      
            } else {
              newDebris = true;
            }
            break;

            case STATE_DEBRIS_TL_MOVE:
            element.x-= 2;
            if (element.y > 2) {
               element.y -=2;
               element.step = 0;
               if (element.y < 24) element.step = 1;
               if (element.y < 16) element.step = 2;  
               if (element.y < 8) element.step = 3;               
            } else {
              newDebris = true;
            }
            break;            

            case STATE_DEBRIS_BR_MOVE:
            element.x+= 2;
            if (element.y < 62) {
               element.y +=2;
               element.step = 0;
               if (element.y > 40) element.step = 1;
               if (element.y > 48) element.step = 2;        
               if (element.y > 56) element.step = 3;      
            } else {
              newDebris = true;
            }
            break;

            case STATE_DEBRIS_BL_MOVE:
            element.x-= 2;
            if (element.y < 62) {
               element.y +=2;
               element.step = 0;
               if (element.y > 40) element.step = 1;
               if (element.y > 48) element.step = 2;        
               if (element.y > 56) element.step = 3;      
            } else {
              newDebris = true;
            }
            break;

            default:
            break;
          }

          if (newDebris) {
            element.x = 64;
            element.y = 32;
            element.state = random(4)+1;       
            element.counter = COUNTER_START; 
          }
          
      }
      sprites.drawSelfMasked(element.x, element.y, IMG_DEBRIS, element.step);
      element.speed_counter++;
    }
    return element;
}

//front enemy handling
LevelElement missile_handle(LevelElement element)
{
    if (element.state > STATE_HIDDEN) {
      if (element.counter > 0) {
        element.counter--;
      } else {

        element.counter = COUNTER_START;

        switch (element.state) {
          case STATE_MISSILE_LAUNCH:
          element.step++;
          element.state = STATE_MISSILE_CLOSE;
          break;

          case STATE_MISSILE_CLOSE:
          //to do: show death graphic
          element.state = STATE_HIDDEN;
          danger = false;
          break;
        }
      }
    }
    if (element.state > STATE_HIDDEN) {
      if (element.state == STATE_EXPLODING) {
        sprites.drawSelfMasked(element.x, element.y, IMG_EXPLOSION, element.step);
        if (element.step < 2) {
              element.step++;
        } else {
            element.state = STATE_HIDDEN;
        }        
      } else {
        sprites.drawSelfMasked(element.x, element.y, IMG_MISSILE, element.step);
      }
    }
    return element;
}

missile_launch(char x, char y) {
  danger = true;
  LevelElement missile = level_element_get(2);
  missile.step = 0;
  missile.x = x+8;
  missile.y = y;
  missile.state = STATE_MISSILE_LAUNCH;
  level_element_update(2, missile);
}

//front enemy handling
LevelElement front_enemy_handle(LevelElement element)
{
    if (element.state > STATE_HIDDEN) {
      if (element.counter > 0) {
        element.counter--;
      } else {

        element.counter = COUNTER_START;
        
        switch (element.state) {
          case STATE_ENEMY_FRONT_IN_LF:
          element.step = 1;
          element.state = STATE_ENEMY_FRONT_LF;
          break;
  
          case STATE_ENEMY_FRONT_IN_RT:
          element.step = 1;
          element.state = STATE_ENEMY_FRONT_RT;
          break;
          
          case STATE_ENEMY_FRONT_LF:
          element.state = STATE_ENEMY_FRONT_BANK_LF;
          if (!danger) missile_launch(element.x, element.y);
          element.step = 2;
          break;
  
          case STATE_ENEMY_FRONT_RT:
          element.state = STATE_ENEMY_FRONT_BANK_RT;
          if (!danger) missile_launch(element.x, element.y);
          element.step = 3;
          break;      
        }  
       }

       if (element.state == STATE_ENEMY_FRONT_BANK_LF || element.state == STATE_ENEMY_FRONT_BANK_RT) {
          if ((element.y - element.speed) > 0) {
            element.y -= element.speed;
          } else {
            element.state = STATE_HIDDEN;
          }
  
          if (element.state == STATE_ENEMY_FRONT_BANK_LF) {
            if ((element.x - element.speed) > 0) {
              element.x -= element.speed;
            } else {
              element.state = STATE_HIDDEN;
            }
          } else {
             if ((element.x - element.speed) < 128) {
              element.x += element.speed;
            } else {
              element.state = STATE_HIDDEN;
            }         
          }
        }
  }
  if (element.state > STATE_HIDDEN) {
    if (element.state == STATE_EXPLODING) { 
      sprites.drawSelfMasked(element.x, element.y, IMG_EXPLOSION, element.step);
      if (element.step < 2) {
              element.step++;
      } else {
            element.state = STATE_HIDDEN;
        }
    } else {
      sprites.drawSelfMasked(element.x, element.y, IMG_ENEMY_FRONT, element.step);
    }
  }

  if (element.state == STATE_HIDDEN) {
        element.state = random(2)+26; 
        switch(element.state) {
          case STATE_ENEMY_FRONT_IN_LF:
          element.x = 32;
          element.y = 18;
          break;

          case STATE_ENEMY_FRONT_IN_RT:
          element.x = 80;
          element.y = 18;
          break;
        }
        element.step = 0;
        element.counter = COUNTER_START;
  }
  return element;
}

//rear enemy handling
LevelElement rear_enemy_handle(LevelElement element)
{
	//---------Y-(0-15)-------
	// 5 (0-41) | 1 (42-85) | 6 (86-127)
	//---------Y-(16-31)------
	// 4 (0-41) | 0 (42-85) | 3 (86-127)
	//---------Y-(32+)--------
	// 4 (0-41) | 2 (42-85) | 3 (86-127)
	//------------------------

	//  STATE_ENEMY_REAR_IN_TL     STATE_ENEMY_REAR_IN_TM     STATE_ENEMY_REAR_IN_TR
	//  STATE_ENEMY_REAR_OUT_BR    STATE_ENEMY_REAR_OUT_BM    STATE_ENEMY_REAR_OUT_BL
	//                           \            |            /
	//  STATE_ENEMY_REAR_IN_ML   -                         -  STATE_ENEMY_REAR_IN_MR
	//  STATE_ENEMY_REAR_OUT_MR                               STATE_ENEMY_REAR_OUT_ML
	//                           /            |            \ 
	//  STATE_ENEMY_REAR_IN_BL     STATE_ENEMY_REAR_IN_BM     STATE_ENEMY_REAR_IN_BR
	//  STATE_ENEMY_REAR_OUT_TR    STATE_ENEMY_REAR_OUT_TM    STATE_ENEMY_REAR_OUT_TL

  if ((element.state > STATE_HIDDEN) && (element.state != STATE_EXPLODING)) {
    if (element.counter > 0) {
      element.counter--;
    } else {
      element.state = random(8)+STATE_ENEMY_REAR_OUT_TL; 
      element.counter = COUNTER_START;
    }
  }
        
	//determine enemy movement
	switch (element.state) {
		case STATE_ENEMY_REAR_IN_TL:
		case STATE_ENEMY_REAR_OUT_BR:
		if ((element.x + element.speed) < 128) {
			element.x += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		
		if ((element.y + element.speed) < 64) {
			element.y += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		break;
			
		case STATE_ENEMY_REAR_IN_TM:
		case STATE_ENEMY_REAR_OUT_BM:
		if ((element.x + element.speed) < 128) {
			element.x += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		break;

		case STATE_ENEMY_REAR_IN_TR:
		case STATE_ENEMY_REAR_OUT_BL:
		if ((element.y + element.speed) < 64) {
			element.y += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		
		if ((element.y - element.speed) > 0) {
			element.y -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}	
		break;		
		
		case STATE_ENEMY_REAR_IN_ML:
		case STATE_ENEMY_REAR_OUT_MR:
		if ((element.y + element.speed) < 64) {
			element.y += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		break;
		
		case STATE_ENEMY_REAR_IN_MR:
		case STATE_ENEMY_REAR_OUT_ML:
		if ((element.y - element.speed) > 0) {
			element.y -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		break;	

		case STATE_ENEMY_REAR_IN_BL:
		case STATE_ENEMY_REAR_OUT_TR:
		if ((element.x - element.speed) > 0) {
			element.x -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		
		if ((element.y + element.speed) < 64) {
			element.y += element.speed;
		} else {
			element.state = STATE_HIDDEN;
		};
		break;		
		
		case STATE_ENEMY_REAR_IN_BM:
		case STATE_ENEMY_REAR_OUT_TM:
		if ((element.x - element.speed) > 0) {
			element.x -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		};
		break;
		
		case STATE_ENEMY_REAR_IN_BR:
		case STATE_ENEMY_REAR_OUT_TL:
		if ((element.x - element.speed) > 0) {
			element.x -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		
		if ((element.y - element.speed) > 0) {
			element.y -= element.speed;
		} else {
			element.state = STATE_HIDDEN;
		}
		break;		
	}

  //determine enemy image to display
    unsigned char enemy_img;
    if (element.x <= 41) {
      enemy_img = 5;
      if (element.state == STATE_ENEMY_REAR_OUT_MR || element.state == STATE_ENEMY_REAR_IN_ML) {
        if (element.y > 15) enemy_img = 4;
      } else {
        if (element.y > 15) enemy_img = 3;       
      }
    }
      
    if (element.x > 41 && element.x <= 85) {
      enemy_img = 1;
      if (element.y > 15) enemy_img = 0; 
      if (element.y > 31) enemy_img = 2;        
    }

    if (element.x > 85) {
      enemy_img = 6;
      if (element.state == STATE_ENEMY_REAR_IN_MR || element.state == STATE_ENEMY_REAR_OUT_ML) {
        if (element.y > 15) enemy_img = 3;      
      } else {
        if (element.y > 15) enemy_img = 4;
      }
    }

   
  if (element.state > STATE_HIDDEN) {
    if (element.state == STATE_EXPLODING) {
      sprites.drawSelfMasked(element.x, element.y, IMG_EXPLOSION, element.step);
      if (element.step < 2) {
              element.step++;
      } else {
            element.state = STATE_HIDDEN;
      } 
    } else {
      sprites.drawSelfMasked(element.x, element.y, IMG_ENEMY_REAR, enemy_img);
    }
  }

  if (element.state == STATE_HIDDEN) {
        element.state = random(2)+10; 
        switch(element.state) {
          case STATE_ENEMY_REAR_IN_TL:
          element.x = 0;
          element.y = 0;
          break;

          case STATE_ENEMY_REAR_IN_TR:
          element.x = 124;
          element.y = 18;
          break;
        }
                  
        element.counter = COUNTER_START; 
  }
  return element;
}

LevelElement element_adjust(LevelElement element, char pitch, char roll)
{
  if (element.state > STATE_HIDDEN)
  {
      if (pitch > 0)
      {
          if (pitch > 3) {
            element.x -=1;
          } else {
            if ( element.counter % 2 == 0) element.x -=1;
          }
      } 

      if (pitch < 0) 
      {
          if (pitch < -3) {
            element.x += 1;
          } else {
            if ( element.counter % 2 == 0) element.x +=1;
          }
      }
  }
  return element;
}

void level_element_handle(char pitch, char roll)
{
  for (char i=0; i < element_count; i++)
  {
    if (levelElements[i].type != TYPE_BULLET) levelElements[i] = element_adjust(levelElements[i], pitch, roll);

    //test for hit with bullets
    for (char b = 0; b < 2; b++) {
      LevelElement bullet = levelElements[b];
      if (bullet.state > STATE_HIDDEN  && bullet.step > 1) {
        if (level_test_element(levelElements[i], 64, 32)) {
          if (levelElements[i].type == TYPE_MISSILE) danger = false;
          levelElements[i].state = STATE_EXPLODING;
          levelElements[i].step = 0;
        }
      }
    }
    
    switch (levelElements[i].type) {
      case TYPE_DEBRIS:
      levelElements[i] = debris_move(levelElements[i]);
      break;

      case TYPE_BULLET:
      levelElements[i] = bullet_move(levelElements[i]);
      break;

      case TYPE_MISSILE:
      levelElements[i] = missile_handle(levelElements[i]);
      break;
      
      case TYPE_ENEMY_REAR:
      levelElements[i] = rear_enemy_handle(levelElements[i]);
      break;

      case TYPE_ENEMY_FRONT:
      levelElements[i] = front_enemy_handle(levelElements[i]);
      break;
    }
    
  }
}
#endif
