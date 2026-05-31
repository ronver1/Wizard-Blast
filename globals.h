/* 
globals.h
Created on: 17 April 2026
Author: Ronit Verma
*/

#include <stdint.h>
#include "Game.h"


extern uint32_t player1Data;
extern uint32_t player2Data;
extern GameState_t currentState;
extern uint32_t playerModeSelect;
extern uint32_t gameResult;
extern uint32_t readyTimer;
extern uint32_t goTimer;
extern uint32_t previousButton;
extern uint32_t currentButton;
extern uint32_t flag;
extern uint32_t languageSelect; // 0 = English, 1 = Spanish
extern const char title[];
extern const char eng[];
extern const char spanish[];
extern const char onePlay[];
extern const char twoPlay[];
extern uint32_t LCDwipe;
extern uint32_t prevX1;
extern uint32_t prevX2;
extern uint32_t prevY1;
extern uint32_t prevY2;
extern int32_t prevXattack1;
extern int32_t prevXattack2;
extern int32_t prevYattack1;
extern int32_t prevYattack2;
extern uint32_t updateHealth1;
extern uint32_t updateHealth2;
extern uint32_t updateScore1;
extern uint32_t updateScore2;
extern uint32_t aiAttack;
extern uint32_t aiJump;