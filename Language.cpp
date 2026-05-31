/* 
Language.cpp
Created on: 12 April 2026
Author: Ronit Verma
*/

#include "Language.h"
#include "globals.h"
#include <string>

phrase_t languagePhrase[10];

void Language_Init(void) {
    languagePhrase[0].english = "Tie Match";
    languagePhrase[0].spanish = "Tie Game";
    languagePhrase[1].english = "One";
    languagePhrase[1].spanish = "Uno";
    languagePhrase[2].english = "Two";
    languagePhrase[2].spanish = "Dos";
    languagePhrase[3].english = "Ready";
    languagePhrase[3].spanish = "Listo";
    languagePhrase[4].english = "Go";
    languagePhrase[4].spanish = "Fuera";
    languagePhrase[5].english = "Health: ";
    languagePhrase[5].spanish = "Salud: ";
    languagePhrase[6].english = "Score: ";
    languagePhrase[6].spanish = "Puntaje: ";
    languagePhrase[7].english = "Paused";
    languagePhrase[7].spanish = "En Pausa";
    languagePhrase[8].english = "Player";
    languagePhrase[8].spanish = "Jugador";
    languagePhrase[9].english = "Wins";
    languagePhrase[9].spanish = "Gana";
}

std::string Language_GetPhrase(uint32_t i) {
    if (languageSelect == 0) {
        return languagePhrase[i].english;
    } else {
        return languagePhrase[i].spanish;
    }
}