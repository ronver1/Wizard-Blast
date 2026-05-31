// Lab9HMain.cpp
// Runs on MSPM0G3507
// Lab 9 ECE319H
// Ronit Verma
// 17 April 2026

#include <stdio.h>
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "../inc/ST7735.h"
#include "../inc/Clock.h"
#include "../inc/LaunchPad.h"
#include "../inc/TExaS.h"
#include "../inc/Timer.h"
#include "../inc/SlidePot.h"
#include "../inc/DAC.h"
#include "SmallFont.h"
#include "LED.h"
#include "Switch.h"
#include "Sound.h"
#include "Sounds.h"
#include "Images.h"
#include "Language.h"
#include "Game.h"
#include "globals.h"

extern "C" void __disable_irq(void);
extern "C" void __enable_irq(void);
extern "C" void TIMG12_IRQHandler(void);


void PLL_Init(void){ // set phase lock loop (PLL)
  // Clock_Init40MHz(); // run this line for 40MHz
  Clock_Init80MHz(0);   // run this line for 80MHz
}

uint8_t TExaS_LaunchPadLogicPB27PB26(void){
  return (0x80|((GPIOB->DOUT31_0>>26)&0x03));
}




// use main1 to observe special characters
int main1(void){ // main1
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf(INITR_BLACKTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
  ST7735_FillScreen(ST7735_WHITE);            // set screen to white
  ST7735_SetRotation(2);
  Language_Init();
  uint32_t i = 0;
  languageSelect = 0;
  uint16_t y = 1;
  std::string ptr = NULL;
  const char* ptr1 = NULL;
  for (i = 0; i < 10; i++) {
    ptr = Language_GetPhrase(i);
    ptr1 = ptr.c_str();
    ST7735_DrawString(1, y, ptr1, ST7735_BLACK);
    y ++;
    Clock_Delay1ms(50);
  }
  languageSelect = 1;
  y = 1;
  for (i = 0; i < 10; i++) {
    ptr = Language_GetPhrase(i);
    ptr1 = ptr.c_str();
    ST7735_DrawString(10, y, ptr1, ST7735_BLACK);
    y++;
    Clock_Delay1ms(50);
  }
  while(1) {
    
  }
}

// use main2 to observe graphics
int main2(void){ // main2
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf(INITR_BLACKTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
  ST7735_FillScreen(ST7735_BLACK);
  ST7735_SetRotation(1);

//  ST7735_DrawBitmap(120, 50, player2Sprite, 32, 32);
//  ST7735_DrawBitmap(120, 70, player2Sprite, 32, 32);
//  ST7735_DrawBitmap(120, 110, player2Sprite, 32, 32);  

//  const char title[] = "Wizard Blast";
//  ST7735_DrawString(8, 4, title, ST7735_WHITE);
/*

  std::string score = "10";
  ST7735_DrawString(0, 11, health.c_str(), ST7735_WHITE);
  SmallFont_OutVertical(10, 35, 115);
*/

  ST7735_FillRect(0, 110, 160, 18, ST7735_LIGHTGREY);
  ST7735_FillRect(0, 0, 160, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(0, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(6, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(12, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(18, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(24, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(3, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(9, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(15, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(21, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(6, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(12, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(18, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(9, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(15, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(12, 37, ST7735_LIGHTGREY);

  ST7735_DrawSmallCircle(154, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(148, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(142, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(136, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(130, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(151, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(145, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(139, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(133, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(148, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(142, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(136, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(145, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(139, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(142, 37, ST7735_LIGHTGREY);

  ST7735_DrawSmallCircle(65, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(71, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(77, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(83, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(89, 25, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(68, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(74, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(80, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(86, 28, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(71, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(77, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(83, 31, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(74, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(80, 34, ST7735_LIGHTGREY);
  ST7735_DrawSmallCircle(77, 37, ST7735_LIGHTGREY);


std::string health = "Health: ";
std::string score = "Score: ";

ST7735_DrawString(0, 0, health.c_str(), ST7735_WHITE);
SmallFont_OutVertical(10, 35, 5);

ST7735_DrawString(0, 1, score.c_str(), ST7735_WHITE);
SmallFont_OutVertical(20, 30, 15);

ST7735_DrawString(12, 0, health.c_str(), ST7735_WHITE);
SmallFont_OutVertical(30, 130, 5);
                
ST7735_DrawString(12, 1, score.c_str(), ST7735_WHITE);
SmallFont_OutVertical(40, 130, 15);

  Clock_Delay1ms(500);
  while(1){
  }
}



// use main3 to test switches and LEDs
uint32_t data = 0;
int main3(void){ // main3
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  Switch_Init(); // initialize switches
  while(1){
    data = Switch_In();
  }
}


// use main4 to test sound outputs
 int main4(void){ 
  uint32_t last=0, now;
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
//  Switch_Init(); // initialize switches
//  LED_Init(); // initialize LED
  Sound_Init();  // initialize sound
  __enable_irq();

//  Sound_PlayMusic(battleMusic, 23928);
//  Sound_PlayMusic(victoryMusic, 56448);
//  Sound_PlayMusic(defeatMusic, 23928);
//  Sound_PlayEffect(selectEffect, 4608);
//  Sound_PlayEffect(attack2Effect, 4608);

 while(1) {
 }
}

uint32_t Player1Data;
uint32_t Player2Data;
// main6 to test slide pot and ADC sampling
int main6(void) {
  __disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  SlidePot Player1;
  SlidePot Player2;
  ADC1_Init();
  ADC0_Init();
  Player1.Init(0, 0, 3);
  Player2.Init(1, 0, 5);

while(1) {
  Player1.Trigger();
  Player2.Trigger();
  Player1Data = Player1.In();
  Player2Data = Player2.In();
  }
}




Player Player1(1);
Player Player2(2);
SlidePot Pot1;
SlidePot Pot2;
int main(void) { // final main
__disable_irq();
  PLL_Init(); // set bus speed
  LaunchPad_Init();
  ST7735_InitPrintf(INITR_BLACKTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
  ST7735_FillScreen(ST7735_BLACK);
  ST7735_SetRotation(1);
  ADC0_Init();
  ADC1_Init();
  Pot1.Init(0, 0, 3);
  Pot2.Init(1, 0, 5);
  Sound_Init();
  Language_Init();
  TimerG12_IntArm(800000, 1);
  Switch_Init();
  Game_Init();
  const char title[] = "Wizard Blast";
  const char eng[] = "English";
  const char spanish [] = "Spanish";
  const char twoPlay[] = "Two Player";
  __enable_irq();
  Sound_PlayMusic(battleMusic, 23928);

  while(1){
    while (flag == 0) {}
      switch (currentState) {
        case START_SCREEN:
          if (LCDwipe == 1) {
            ST7735_FillRect(0, 0, 200, 200, ST7735_BLACK);
            LCDwipe = 0;
          }
          ST7735_DrawString(8, 2, title, ST7735_WHITE);
          if (languageSelect == 0) {
            ST7735_DrawString(4, 5, eng, ST7735_YELLOW);
            ST7735_DrawString(4, 6, spanish, ST7735_WHITE);
          } else {
            ST7735_DrawString(4, 6, spanish, ST7735_YELLOW);
            ST7735_DrawString(4, 5, eng, ST7735_WHITE);
          }
          if (playerModeSelect == 1) {
            ST7735_DrawString(8, 9, twoPlay, ST7735_YELLOW);
          }
          break;    // START_SCREEN break

          // case READY_SCREEN:
          case READY_SCREEN:
            if (LCDwipe == 1) {
              ST7735_FillScreen(ST7735_BLACK);
              ST7735_DrawString(10, 2, Language_GetPhrase(3).c_str(), ST7735_WHITE);
              LCDwipe = 0;
            }
              
          break;    // READY_SCREEN break

          case GO_SCREEN:
            if (LCDwipe == 1) {
              ST7735_FillScreen(ST7735_BLACK);
              ST7735_DrawString(10, 2, Language_GetPhrase(4).c_str(), ST7735_WHITE);
              LCDwipe = 0;
            }
            
          break;    // GO_SCREEN break

          case FIGHT_SCREEN:
            if (LCDwipe == 1) {
              ST7735_FillScreen(ST7735_BLACK);
              // Draw Stage
              
              ST7735_FillRect(0, 0, 160, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(0, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(6, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(12, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(18, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(24, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(3, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(9, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(15, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(21, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(6, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(12, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(18, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(9, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(15, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(12, 37, ST7735_LIGHTGREY);

              ST7735_DrawSmallCircle(154, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(148, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(142, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(136, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(130, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(151, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(145, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(139, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(133, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(148, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(142, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(136, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(145, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(139, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(142, 37, ST7735_LIGHTGREY);

              ST7735_DrawSmallCircle(65, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(71, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(77, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(83, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(89, 25, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(68, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(74, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(80, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(86, 28, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(71, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(77, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(83, 31, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(74, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(80, 34, ST7735_LIGHTGREY);
              ST7735_DrawSmallCircle(77, 37, ST7735_LIGHTGREY);
              ST7735_FillRect(0, 110, 160, 18, ST7735_LIGHTGREY);

              LCDwipe = 0;
            }

            if (playerModeSelect == 1) {
              if (Player1.IsAlive() == 1) {
                ST7735_FillRect(prevX1, prevY1 - 32, 32, 32, ST7735_BLACK);
                ST7735_DrawBitmap(Player1.Get_Xpos(), Player1.Get_Ypos(), player1Sprite, 32, 32);
                prevX1 = Player1.Get_Xpos();
                prevY1 = Player1.Get_Ypos();
              }
              if (Player2.IsAlive() == 1) {
                ST7735_FillRect(prevX2, prevY2 - 32, 32, 32, ST7735_BLACK);
                ST7735_DrawBitmap(Player2.Get_Xpos(), Player2.Get_Ypos(), player2Sprite, 32, 32);
                prevX2 = Player2.Get_Xpos();
                prevY2 = Player2.Get_Ypos();
              }
              if (Player1.IsAttack() == 1) {
                ST7735_FillRect(prevXattack1, prevYattack1 - 16, 16, 16, ST7735_BLACK);
                ST7735_DrawBitmap(Player1.Get_Xattack(), Player1.Get_Yattack(), player1Attack, 16, 16);
                prevXattack1 = Player1.Get_Xattack();
                prevYattack1 = Player1.Get_Yattack();
              } else {
                ST7735_FillRect(prevXattack1, prevYattack1 - 16, 16, 16, ST7735_BLACK);
              }
              if (Player2.IsAttack() == 1) {
                ST7735_FillRect(prevXattack2, prevYattack2 - 16, 16, 16, ST7735_BLACK);
                ST7735_DrawBitmap(Player2.Get_Xattack(), Player2.Get_Yattack(), player2Attack, 16, 16);
                prevXattack2 = Player2.Get_Xattack();
                prevYattack2 = Player2.Get_Yattack();
              } else {
                ST7735_FillRect(prevXattack2, prevYattack2 - 16, 16, 16, ST7735_BLACK);
              }
              if (prevXattack1 != -1 && Player1.IsAttack() == 0) {
                ST7735_FillRect(prevXattack1, prevYattack1 - 16, 16, 16, ST7735_BLACK);
                prevXattack1 = -1;
                prevYattack1 = -1;
              }
              if (prevXattack2 != -1 && Player2.IsAttack() == 0) {
                ST7735_FillRect(prevXattack2, prevYattack2 - 16, 16, 16, ST7735_BLACK);
                prevXattack2 = -1;
                prevYattack2 = -1;
              }
              if (Player1.IsAlive() == 1) {
                if (updateHealth1 == 1) {
                  ST7735_DrawString(0, 0, Language_GetPhrase(5).c_str(), ST7735_WHITE);
                  SmallFont_OutVertical(Player1.Get_Health(), 35, 5);
                  updateHealth1 = 0;
                }
                if (updateScore1 == 1) {
                  ST7735_DrawString(0, 1, Language_GetPhrase(6).c_str(), ST7735_WHITE);
                  SmallFont_OutVertical(Player1.Get_Score(), 30, 15);
                  updateScore1 = 0;
                }
              }
              if (Player2.IsAlive() == 1) {
                if (updateHealth2 == 1) {
                  ST7735_DrawString(12, 0, Language_GetPhrase(5).c_str(), ST7735_WHITE);
                  SmallFont_OutVertical(Player2.Get_Health(), 130, 5);
                  updateHealth2 = 0;
                }
                if (updateScore2 == 1) {
                  ST7735_DrawString(12, 1, Language_GetPhrase(6).c_str(), ST7735_WHITE);
                  SmallFont_OutVertical(Player2.Get_Score(), 130, 15);
                  updateScore2 = 0;
              }
            }

      }
      
      break;

      case PAUSE_SCREEN:
        break;

      case END_SCREEN:
      if (LCDwipe == 1) {
        ST7735_FillScreen(ST7735_BLACK);
        LCDwipe = 0;
      }
      if (gameResult == 1) {    // Player 1 Loses
      ST7735_DrawString(3, 2, Language_GetPhrase(8).c_str(), ST7735_WHITE);
      ST7735_DrawString(11, 2, Language_GetPhrase(2).c_str(), ST7735_WHITE);
      ST7735_DrawString(14, 2, Language_GetPhrase(9).c_str(), ST7735_WHITE);
      ST7735_DrawBitmap(110, 50, player2Sprite, 32, 32);
      ST7735_DrawBitmap(60, 50, player2Attack, 16, 16);
      ST7735_DrawBitmap(140, 50, player2Attack, 16, 16);
      }
      if (gameResult == 2) {
      ST7735_DrawString(3, 2, Language_GetPhrase(8).c_str(), ST7735_WHITE);
      ST7735_DrawString(11, 2, Language_GetPhrase(1).c_str(), ST7735_WHITE);
      ST7735_DrawString(14, 2, Language_GetPhrase(9).c_str(), ST7735_WHITE);
      ST7735_DrawBitmap(110, 50, player1Sprite, 32, 32);
      ST7735_DrawBitmap(60, 50, player1Attack, 16, 16);
      ST7735_DrawBitmap(140, 50, player1Attack, 16, 16);
      }
      if (gameResult == 3) {
        ST7735_DrawString(11, 2, Language_GetPhrase(0).c_str(), ST7735_WHITE);
        ST7735_DrawBitmap(60, 50, player1Sprite, 32, 32);
        ST7735_DrawBitmap(140, 50, player2Sprite, 32, 32);
      }

    }
    flag = 0; 
  }
}




void TIMG12_IRQHandler(void){
  if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
    // Game Engine Start
        currentButton = Switch_In();
    
    switch(currentState) {
        case START_SCREEN:
        
        if (((previousButton & 0x01) == 1) && ((currentButton & 0x01) == 0)) {
            Sound_PlayEffect(selectEffect, 3283);
            languageSelect = (languageSelect + 1) % 2;
        }

        if (((previousButton & 0x02) == 2) && ((currentButton & 0x02) == 0)) {
            Sound_PlayEffect(selectEffect, 3283);
        }

        if (((previousButton & 0x04) == 4) && ((currentButton & 0x04) == 0)) {
            Sound_PlayEffect(selectEffect, 3283);
            currentState = READY_SCREEN;
            Sound_Stop();
            LCDwipe = 1;
            break;
        }

        break;      // START_SCREEN break

        case READY_SCREEN:
        if (readyTimer >= 200) {
            currentState = GO_SCREEN;
            Sound_Stop();
            LCDwipe = 1;
            break;
        } else {
            readyTimer++;
        }

        break;      // READY_SCREEN break

        case GO_SCREEN:
        if (goTimer >=200) {
            currentState = FIGHT_SCREEN;
            Sound_PlayMusic(battleMusic, 23928);
            LCDwipe = 1;
            break;
        } else {
            goTimer++;
        }
        
        break;      // GO_SCREEN break

        case FIGHT_SCREEN:
        if (playerModeSelect == 1) {

            Pot1.Trigger();
            Pot2.Trigger();
            player1Data = Pot1.In();
            player2Data = Pot2.In();
            player1Data = (player1Data>>5);
            player2Data = (player2Data>>5);
            Player1.Change_Xpos(player1Data);
            Player2.Change_Xpos(player2Data);

            if (Player1.attackCoolDown() != 0) {
                Player1.attackTimer--;
            }
            if (Player2.attackCoolDown() != 0) {
                Player2.attackTimer--;
            }
            if (Player1.jumpCoolDown() != 0) {
                Player1.jumpTimer--;
            }
            if (Player2.jumpCoolDown() != 0) {
                Player2.jumpTimer--;
            }
            if (Player1.selfHit != 0) {
                Player1.selfHit--;
            }
            if (Player2.selfHit != 0) {
                Player2.selfHit--;
            }
            if (Player1.Get_Ypos() <= 55) {
                Player1.jumpPhase = 2;
            }
            if (Player1.jumpPhase != 0) {
                if (Player1.jumpPhase == 1) {
                    Player1.Change_Ypos(Player1.Get_Ypos() - 2);
                } else {
                    Player1.Change_Ypos(Player1.Get_Ypos() + 2);
                }
            }
            if (Player2.Get_Ypos() <= 55) {
                Player2.jumpPhase = 2;
            }
            if (Player2.jumpPhase != 0) {
                if (Player2.jumpPhase == 1) {
                    Player2.Change_Ypos(Player2.Get_Ypos() - 2);
                } else {
                    Player2.Change_Ypos(Player2.Get_Ypos() + 2);
                }
            }
            if (Player1.Get_Ypos() >= 110) {
                Player1.Change_Ypos(110);
                Player1.jumpPhase = 0;
            }
            if (Player2.Get_Ypos() >= 110) {
                Player2.Change_Ypos(110);
                Player2.jumpPhase = 0;
            }

            if (((previousButton & 0x01) == 1) && ((currentButton & 0x01) == 0) && (Player1.attackTimer == 0)) {
                // Player 1 Attack
                Sound_PlayEffect(selectEffect, 1313);
                Player1.Change_Xattack(Player1.Get_Xpos());
                Player1.Change_Yattack(Player1.Get_Ypos());
                Player2.XoldPos = Player2.Get_Xpos();
                Player2.YoldPos = Player2.Get_Ypos();
                Player1.attackTimer = 60;
                Player1.selfHit = 16;
            }
            if (((previousButton & 0x02) == 2) && ((currentButton & 0x02) == 0) && (Player1.jumpTimer == 0)) {
                // Player 1 Jump
                Sound_PlayEffect(jumpEffect, 5128);
                Player1.jumpPhase = 1;
                Player1.jumpTimer = 40;          
            }
            if (((previousButton & 0x04) == 4) && ((currentButton & 0x04) == 0)) {
                currentState = PAUSE_SCREEN;
                Sound_Stop();
                break;
            }
            if (((previousButton & 0x08) == 8) && ((currentButton & 0x08) == 0) && (Player2.jumpTimer == 0)) {
                // Player 2 Jump
                Sound_PlayEffect(jumpEffect, 5128);
                Player2.jumpPhase = 1;
                Player2.jumpTimer = 40;
            }
            if (((previousButton & 0x40) == 64) && ((currentButton & 0x40) == 0) && Player2.attackTimer == 0) {
                // Player 2 Attack
                Sound_PlayEffect(selectEffect, 1313);
                Player2.Change_Xattack(Player2.Get_Xpos());
                Player2.Change_Yattack(Player2.Get_Ypos());
                Player1.XoldPos = Player1.Get_Xpos();
                Player1.YoldPos = Player1.Get_Ypos();
                Player2.attackTimer = 60;
                Player2.selfHit = 16;
            }

            if (Player1.Get_Xattack() > 0 && Player1.Get_Xattack() < 130) {
                if (Player1.Get_Xattack() < Player2.XoldPos) {
                    Player1.Change_Xattack(Player1.Get_Xattack() + 2);
                } else {
                    Player1.Change_Xattack(Player1.Get_Xattack() - 2);
                }
            } else {
                Player1.Change_Xattack(-1);
                Player1.Change_Yattack(-1);
            }
            if (Player2.Get_Xattack() > 0 && Player2.Get_Xattack() < 130) {
                if (Player2.Get_Xattack() < Player1.XoldPos) {
                    Player2.Change_Xattack(Player2.Get_Xattack() + 2);
                } else {
                    Player2.Change_Xattack(Player2.Get_Xattack() - 2);
                }
            } else {
                Player2.Change_Xattack(-1);
                Player2.Change_Yattack(-1);
            }

            // Collision Detection
            // Collide with Other Fireball
            if (Player1.IsAttack() == 1 && Player2.IsAttack() == 1) {
                if (((Player2.Get_Xattack() + 16) > Player1.Get_Xattack()) && (Player2.Get_Xattack() < (Player1.Get_Xattack() + 16)) && (Player2.Get_Yattack() > (Player1.Get_Yattack() - 16)) && ((Player2.Get_Yattack() - 16) < Player1.Get_Yattack())) {
                    // Fireballs collide
                    Player1.Change_Xattack(-1);
                    Player1.Change_Yattack(-1);
                    Player2.Change_Xattack(-1);
                    Player2.Change_Yattack(-1);
                }
            }
            // Collide with Opponent
            if (Player1.IsAttack() == 1) {
                if (((Player1.Get_Xattack() + 16) > Player2.Get_Xpos()) && (Player1.Get_Xattack() < (Player2.Get_Xpos() + 32)) && (Player1.Get_Yattack() > (Player2.Get_Ypos() - 32)) && ((Player1.Get_Yattack() - 16) < Player2.Get_Ypos())) {
                    // Player 1 fireball hits Player 2
                    Player2.Change_Health(Player2.Get_Health() - 10);
                    updateHealth2 = 1;
                    Player1.Change_Score(Player1.Get_Score() + 5);
                    updateScore1 = 1;
                    Player1.Change_Xattack(-1);
                    Player1.Change_Yattack(-1);
                }
            }
            if (Player2.IsAttack() == 1) {
                if (((Player2.Get_Xattack() + 16) > Player1.Get_Xpos()) && (Player2.Get_Xattack() < (Player1.Get_Xpos() + 32)) && (Player2.Get_Yattack() > (Player1.Get_Ypos() - 32)) && ((Player2.Get_Yattack() - 16) < Player1.Get_Ypos())) {
                    // Player 2 fireball hits Player 1
                    Player1.Change_Health(Player1.Get_Health() - 10);
                    updateHealth1 = 1;
                    Player2.Change_Score(Player2.Get_Score() + 5);
                    updateScore2 = 1;
                    Player2.Change_Xattack(-1);
                    Player2.Change_Yattack(-1);
                }
            }
            // Collide with oneself
            if (Player1.IsAttack() == 1) {
                // Player 1 fireball hits Player 1
                if (((Player1.Get_Xattack() + 16) > Player1.Get_Xpos()) && (Player1.Get_Xattack() < (Player1.Get_Xpos() + 32)) && (Player1.Get_Yattack() > (Player1.Get_Ypos() - 32)) && ((Player1.Get_Yattack() - 16) < Player1.Get_Ypos()) && (Player1.selfHit == 0)) {
                    Player1.Change_Health(Player1.Get_Health() - 5);
                    Player1.Change_Score(Player1.Get_Score() - 5);
                    Player1.Change_Xattack(-1);
                    Player1.Change_Yattack(-1);
                }
            }
            if (((Player1.Get_Xattack() + 16) > 128) && (Player1.Get_Xattack() < 128)) {
              Player1.Change_Xattack(-1);
              Player1.Change_Yattack(-1);
            }
            if (((Player2.Get_Xattack() + 16) > 128) && (Player2.Get_Xattack() < 128)) {
              Player2.Change_Xattack(-1);
              Player2.Change_Yattack(-1);
            }
            if (Player2.IsAttack() == 1) {
                // Player 2 fireball hits Player 2
                if (((Player2.Get_Xattack() + 16) > Player2.Get_Xpos()) && (Player2.Get_Xattack() < (Player2.Get_Xpos() + 32)) && (Player2.Get_Yattack() > (Player2.Get_Ypos() - 32)) && ((Player2.Get_Yattack() - 16) < Player2.Get_Ypos()) && Player2.selfHit == 0) {
                    Player2.Change_Health(Player2.Get_Health() - 5);
                    Player2.Change_Score(Player2.Get_Score() - 5);
                    Player2.Change_Xattack(-1);
                    Player2.Change_Yattack(-1);
                }
            }

            
            if ((Player1.Get_Health() <= 0 && Player2.Get_Health() <= 0) || (Player1.Get_Health() > 100 && Player2.Get_Health() > 100)) {
                gameResult = 3;
                currentState = END_SCREEN;
                Sound_PlayMusic(battleMusic, 23928);
                LCDwipe = 1;
                break;
            }
            if ((Player1.Get_Health() <= 0) || (Player1.Get_Health() > 100)) {
                gameResult = 1;
                currentState = END_SCREEN;
                Sound_PlayMusic(battleMusic, 23928);
                LCDwipe = 1;
                break;
            } 
            
            if ((Player2.Get_Health() <= 0) || (Player2.Get_Health() > 100)) {
                gameResult = 2;
                currentState = END_SCREEN;
                Sound_PlayMusic(battleMusic, 23928);
                LCDwipe = 1;
                break;
            }
        }

        break;      // FIGHT_SCREEN break

        case PAUSE_SCREEN:
        if (((previousButton & 0x04) == 4) && ((currentButton & 0x04) == 0)) {
            currentState = FIGHT_SCREEN;
            Sound_PlayMusic(battleMusic, 23928);
            break;
        }
        
        break;      // PAUSE_SCREEN break

        case END_SCREEN:
        if (((previousButton & 0x04) == 4) && ((currentButton & 0x04) == 0)) {
            Game_Init();
            LCDwipe = 1;
            Sound_PlayMusic(battleMusic, 23928);
            Player1.Player_reInit();
            Player2.Player_reInit();
            break;
        }

        break;      // END_SCREEN break

    }

    flag = 1;
    previousButton = currentButton;
    // Game Engine End
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
  }
}


