// File: input.h
// Header for: input.c
// Author: Jaka Kordez

#ifndef INP_DG
#define INP_DG

#include "stm32f4xx_hal.h"

typedef struct {
	uint16_t Buttons;
	int8_t Encoder1;
	int8_t Encoder2;
}UserInput;

UserInput GetUserInput(void);

#endif
