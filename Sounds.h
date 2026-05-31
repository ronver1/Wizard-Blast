// Sound.h
// Runs on MSPM0
// Play sounds on 12-bit DAC.
// Your name
// 11/5/2023
#ifndef SOUNDS_H
#define SOUNDS_H
#include <stdint.h>
#include "Sound.h"

// initialize a 11kHz SysTick, however no sound should be started
// initialize any global variables
// Initialize the 5 bit DAC
// This is called once
void Sound_Init(void);

//******* Sound_Start ************
// This function does not output to the DAC. 
// Rather, it sets a pointer and counter, and then enables the SysTick interrupt.
// It starts the sound, and the SysTick ISR does the output
// feel free to change the parameters
// Sound should play once and stop
// Input: pt is a pointer to an array of DAC outputs
//        count is the length of the array
// Output: none
// special cases: as you wish to implement

// following functions do not output to the DAC
// they configure pointers/counters and initiate the sound by calling Sound_Start

void Sound_PlayEffect(const uint16_t *pt, uint32_t len);
void Sound_PlayMusic(const uint16_t *pt, uint32_t len);
void Sound_Stop();

#endif
