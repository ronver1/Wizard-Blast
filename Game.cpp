/* 
Game.cpp
Created on: 15 April 2026
Author: Ronit Verma
*/

#include "Game.h"
#include <stdint.h>
#include <cmath>
#include "Language.h"
#include "Switch.h"
#include "Sounds.h"
#include "Sound.h"
#include "globals.h"



void Game_Init(void) {
    playerModeSelect = 1;
    languageSelect = 0;
    gameResult = 0;
    readyTimer = 0;
    goTimer = 0;
    previousButton = 0;
    LCDwipe = 0;
    prevX1 = 200;
    prevX2 = 200;
    prevY1 = 200;
    prevY2 = 200;
    prevXattack1 = 200;
    prevXattack2 = 200;
    prevYattack1 = 200;
    prevYattack2 = 200;
    updateHealth1 = 0;
    updateHealth2 = 0;
    updateScore1 = 0;
    updateScore2 = 0;
    currentState = START_SCREEN;
    aiAttack = 10;
    aiJump = 0;
}

void Game_Tick() {

}




Player::Player(uint32_t num) {
    this->num = num;
    if (num == 2) {
        this->Xpos = 10;
        this->XoldPos = 10;
    } else {
        this->Xpos = 120;
        this->XoldPos = 120;
    }
    this->Ypos = 110;
    this->health = 100;
    this->score = 0;
    this->Xattack = -1;
    this->Yattack = -1;
    this->attackTimer = 0;
    this->jumpTimer = 0;
    this->YoldPos = 110;
}


uint32_t Player::Get_Xpos() {
    return this->Xpos;
}

uint32_t Player::Get_Ypos() {
    return this->Ypos;
}

uint32_t Player::Get_Health() {
    return this->health;
}

uint32_t Player::Get_Score() {
    return this->score;
}

uint32_t Player::IsAlive() {
    if (this->health > 0) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t Player::attackCoolDown() { 
    return this->attackTimer;
}

uint32_t Player::jumpCoolDown() {
    return this->jumpTimer;
}

uint32_t Player::IsAttack() {
    if (this->Xattack != -1 && this->Yattack != -1) {
        return 1;
    } else {
        return 0;
    }
}

int32_t Player::Get_Xattack() {
    return this->Xattack;
}

int32_t Player::Get_Yattack() {
    return this->Yattack;
}

void Player::Change_Xpos(uint32_t newX) {
    this->Xpos = newX;
}

void Player::Change_Ypos(uint32_t newY) {
    this->Ypos = newY;
}

void Player::Change_Xattack(int32_t newX) {
    this->Xattack = newX;
}

void Player::Change_Yattack(int32_t newY) {
    this->Yattack = newY;
}

void Player::Change_Health(uint32_t newHealth) {
    this->health = newHealth;
}

void Player::Change_Score(uint32_t newScore) {
    this->score = newScore;
}

uint32_t Player::IsJump() {
    if (this->Ypos == 110) {
        return 0;
    } else {
        return 1;
    }
}

void Player::Player_reInit(void) {
    if (this->num == 2) {
        this->Xpos = 10;
        this->XoldPos = 10;
    } else {
        this->Xpos = 120;
        this->XoldPos = 120;
    }
    this->Ypos = 110;
    this->health = 100;
    this->score = 0;
    this->Xattack = -1;
    this->Yattack = -1;
    this->attackTimer = 0;
    this->jumpTimer = 0;
    this->YoldPos = 110;
}