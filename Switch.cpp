/* 
Switch.cpp
Created on: 12 April 2026
Author: Ronit Verma
*/


#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
#include "Switch.h"

void Switch_Init(void){
  IOMUX->SECCFG.PINCM[PA16INDEX] = 0x00040081; 
  IOMUX->SECCFG.PINCM[PA17INDEX] = 0x00040081; 
  IOMUX->SECCFG.PINCM[PB20INDEX] = 0x00040081; 
  IOMUX->SECCFG.PINCM[PB17INDEX] = 0x00040081; 
  IOMUX->SECCFG.PINCM[PB16INDEX] = 0x00040081; 

  GPIOA->DOE31_0 &= ~0x30000;
  GPIOB->DOE31_0 &= ~0x130000;
}


// return current state of switches
uint32_t Switch_In(void){
  uint32_t dataA = GPIOA->DIN31_0;
  uint32_t dataB = GPIOB->DIN31_0;
  uint32_t result = 0x00;

  dataA &= 0x30000;
  dataB &= 0x130000;

  dataA = dataA>>16;
  dataB = dataB>>14;
  result = dataA | dataB;
  return result;
  /*
  Result Bit Mapping:
  Bit 0: P1 Attack (#1)
  Bit 1: P1 Jump (#2)
  Bit 2: Control (#4)
  Bit 3: P2 Jump (#8)
  Bit 6: P2 Attack (#64)
  */
}
