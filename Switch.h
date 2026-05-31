/* 
Sound.h
Created on: 12 April 2026
Author: Ronit Verma
*/

#ifndef SWITCH_H
#define SWITCH_H

// initialize your switches
void Switch_Init(void);

/* return current state of switches
  Result Bit Mapping:
  Bit 0: P1 Attack (#0)
  Bit 1: P1 Jump (#1)
  Bit 2: Control (#4)
  Bit 3: P2 Jump (#8)
  Bit 6: P2 Attack (#64) */
uint32_t Switch_In(void);



#endif
