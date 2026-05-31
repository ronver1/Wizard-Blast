/* 
globals.cpp
Created on: 17 April 2026
Author: Ronit Verma
*/

#include <stdint.h>
#include "Game.h"



 uint32_t player1Data;
 uint32_t player2Data;
 GameState_t currentState;
 uint32_t playerModeSelect;
 uint32_t gameResult;
 uint32_t readyTimer;
 uint32_t goTimer;
 uint32_t previousButton;
 uint32_t currentButton;
 uint32_t flag;
 uint32_t languageSelect; // 0 = English, 1 = Spanish
 uint32_t LCDwipe;
 uint32_t prevX1;
 uint32_t prevX2;
 uint32_t prevY1;
 uint32_t prevY2;
 int32_t prevXattack1;
 int32_t prevXattack2;
 int32_t prevYattack1;
 int32_t prevYattack2;
 uint32_t updateHealth1; 
 uint32_t updateHealth2; 
 uint32_t updateScore1;
 uint32_t updateScore2;
 uint32_t aiAttack;
 uint32_t aiJump;
