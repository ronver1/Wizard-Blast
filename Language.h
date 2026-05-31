/* 
Language.h
Created on: 12 April 2026
Author: Ronit Verma
*/

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <stdint.h>
#include <string>

typedef struct phrase_t {
    std::string english;
    std::string spanish;
} phrase_t;

extern phrase_t languagePhrase[10];
             

void Language_Init(void);
std::string Language_GetPhrase(uint32_t i);

#endif