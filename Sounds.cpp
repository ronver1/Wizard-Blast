// Sound.cpp
// Runs on MSPM0
// Sound assets in sounds/sounds.h
// your name
// your data 
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "Sound.h"
#include "Sounds.h"
#include "../inc/DAC.h"
#include "../inc/Timer.h"
#include "../inc/Clock.h"
#include "../inc/LaunchPad.h"


// Sound effect state
static volatile const uint16_t* effectBuf = 0;
static volatile uint32_t effectLen = 0;
static volatile uint32_t effectIdx = 0;
static volatile uint8_t effectPlaying = 0;

// Background music state
static volatile const uint16_t* musicBuf = 0;
static volatile uint32_t musicLen = 0;
static volatile uint32_t musicIdx = 0;
static volatile uint8_t musicPlaying = 0;


void SysTick_IntArm(uint32_t period, uint32_t priority) {
  SysTick->LOAD = period - 1;

  SysTick->VAL = 0x00;

  SysTick->CTRL &= 0xFFFFFFF8;
  SysTick->CTRL |= 0x07;
  SCB->SHP[1] = priority;

}

void DAC_Init(void){
    // Reset DAC and VREF
    // RSTCLR
    //   bits 31-24 unlock key 0xB1
    //   bit 1 is Clear reset sticky bit
    //   bit 0 is reset ADC
  VREF->GPRCM.RSTCTL = 0xB1000003;
  DAC0->GPRCM.RSTCTL = 0xB1000003;

    // Enable power ADC and VREF
    // PWREN
    //   bits 31-24 unlock key 0x26
    //   bit 0 is Enable Power
  VREF->GPRCM.PWREN = 0x26000001;
  DAC0->GPRCM.PWREN = 0x26000001;

  Clock_Delay(24); // time for ADC and VREF to power up


  VREF->CLKSEL = 0x00000008; // bus clock
  VREF->CLKDIV = 0; // divide by 1
  VREF->CTL0 = 0x0001;
  // bit 8 SHMODE = off
  // bit 7 BUFCONFIG=0 for 2.5 (=1 for 1.4)
  // bit 0 is enable
  VREF->CTL2 = 0;
  // bits 31-16 HCYCLE=0
    // bits 15-0 SHCYCLE=0
  while((VREF->CTL1&0x01)==0){}; // wait for VREF to be ready
  // CTL0
  // bit 16 DFM 0 straight binary
  // bit 8 RES 1 12-bit
  // bit 0 ENABLE 1 for on, 0 for disable
  DAC0->CTL0 = 0x0100; // 12-bit, straight, disable
  // CTL1
  // bit 24 OPS 1 OUT0 is selected
  // bit 9 REFSN 0 VR- is VrefN, 1 for analog ground
  // bit 8 REFSP 1 VR+ is VrefP, 0 for analog supply
  // bit 1 AMPHIZ 0 HiZ when disabled
  // bit 0 AMPEN 1 enabled
  DAC0->CTL1 = (1<<24)|(1<<9)|(1<<8)|1;
 // DAC0->CTL1 = (1<<24)|(1<<9)|1;
  DAC0->CTL2 = 0; // no DMA, no FIFO trigger
  // CTL3
  // bits 11-8 STIMCONFIG n=0 for 500 sps
  //     for n = 0 to 5 500*2^n sps (500 to  16k)
  //     n=6 100 ksps
  //     n=7 200 ksps
  //     n=8 500 ksps
  //     n=9 1 Msps
  // bit 0 STIMEN =0 disable sample time generator
  DAC0->CTL3 = 0x0700; // no sample time generator
  DAC0->CTL0 = 0x0101; // 12-bit, straight, enable
}

void DAC_Out(uint32_t data){
  DAC0->DATA0 = data;
}

// initialize a 11kHz SysTick, however no sound should be started
// initialize any global variables
// Initialize the 5 bit DAC

void Sound_Init(void) {
  SysTick_IntArm(7256, 0);    // SysTick Timer Init
  DAC_Init();                 // 12 bit DAC Init
}
extern "C" void SysTick_Handler(void);

void SysTick_Handler(void) { 
  if (effectPlaying == 1) {
    DAC_Out(effectBuf[effectIdx]);
    effectIdx++;
    if (effectIdx >= effectLen) {
      effectPlaying = 0;
      effectIdx = 0;
    }
  } else if (musicPlaying == 1) {
    DAC_Out(musicBuf[musicIdx]);
    musicIdx++;
    if (musicIdx >= musicLen) {
      musicIdx = 0;
    }
  } else {
    DAC_Out(2048);
  }

}

//******* Sound Functions ************
// This function does not output to the DAC. 
// Rather, it sets a pointer and counter, and then enables the SysTick interrupt.
// It starts the sound, and the SysTick ISR does the output
// feel free to change the parameters
// Sound should play once and stop
// Input: pt is a pointer to an array of DAC outputs
//        len is the length of the array
// Output: none
// special cases: as you wish to implement
void Sound_PlayEffect(const uint16_t *pt, uint32_t len) {
  __disable_irq();
  effectPlaying = 1;
  effectIdx = 0;
  effectLen = len;
  effectBuf = pt;
  __enable_irq();
}

void Sound_PlayMusic(const uint16_t *pt, uint32_t len) {
  __disable_irq();
  musicPlaying = 1;
  musicIdx = 0;
  musicLen = len;
  musicBuf = pt;
  __enable_irq();
}

void Sound_Stop() {
  __disable_irq();
  effectPlaying = 0;
  musicPlaying = 0;
  __enable_irq();
}