// File: oscilloscope.h
// Header for: oscilloscope.c
// Author: Jaka Kordez

#ifndef OSC_DG
#define OSC_DG

#include "stm32f4xx_hal.h"

#define OSC_RAM_Capacity 		8388608-153600 // Ram capacity in bytes

// Time defines

typedef enum { IM = 1000000, IIM = 2000000, VM = 5000000, XM = 10000000, XXM = 20000000, XLM = 40000000 }OSC_Time_SampleRates;

uint32_t OSC_Position;

#endif
