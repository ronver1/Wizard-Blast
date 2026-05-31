/* 
Game.h
Created on: 15 April 2026
Author: Ronit Verma
*/

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

void Game_Init(void);
void Game_Tick(void);

class Player {
private:
    uint32_t Xpos;              // Sprite X position
    uint32_t Ypos;              // Sprite Y Position
    uint32_t health;            // Player Health
    uint32_t score;             // Player Score
    int32_t Xattack;            // Attack X Position, -1 if none
    int32_t Yattack;            // Attack Y Position, -1 if none
public:
    uint32_t attackTimer;       // Set to 50 upon attack (100Hz ISR and 500ms cooldown)
    uint32_t jumpTimer;         // Set to 30 upon jump (100Hz ISR and 300ms cooldown)
    uint32_t XoldPos;
    uint32_t YoldPos;
    uint32_t selfHit;
    int32_t jumpPhase;
    uint32_t num;
public:
    Player(uint32_t num);                           // Constructor, Input is Player 1/2
    void Player_reInit();
    uint32_t Get_Xpos();                            // Returns sprite X Position
    uint32_t Get_Ypos();                            // Returns sprite Y Position
    uint32_t Get_Health();                          // Returns Health
    uint32_t Get_Score();                           // Returns Score
    uint32_t IsAlive();                             // Returns 1 if Alive, 0 if Dead
    uint32_t IsJump();                              // Returns 1 if Jumping, 0 if not
    uint32_t attackCoolDown();                          // Timer Cool Down 500ms
    uint32_t jumpCoolDown();                            // Timer Cool Down 300ms
    uint32_t IsAttack();                            // Returns 1 if there is an active fireball, 0 if not
    int32_t Get_Xattack();                          // Returns X position of active fireball, -1 if none
    int32_t Get_Yattack();                          // Returns Y position of active fireball, -1 if none
    void Change_Xpos(uint32_t newX);                // Changes sprite X position
    void Change_Ypos(uint32_t newY);                // Changes sprite Y position
    void Change_Xattack(int32_t newX);              // Changes fireball X position
    void Change_Yattack(int32_t newY);              // Changes fireball X position
    void Change_Health(uint32_t newHealth);         // Decrement Health if collision with fireball
    void Change_Score(uint32_t newScore);           // Increment Score if successful collision 
    
};

typedef enum {
    START_SCREEN,
    READY_SCREEN,
    GO_SCREEN,
    FIGHT_SCREEN,
    PAUSE_SCREEN,
    END_SCREEN
} GameState_t;

#endif