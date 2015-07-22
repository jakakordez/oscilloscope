// File: oscilloscope.h
// Header for: oscilloscope.c
// Author: Jaka Kordez

#ifndef OSC_DG
#define OSC_DG

#include "stm32f4xx_hal.h"

#define OSC_RAM_Capacity 		8388608-153600 // Ram capacity in bytes

// Time defines

typedef enum { IM = 1000000, IIM = 2000000, VM = 5000000, XM = 10000000, XXM = 20000000, XLM = 40000000 }OSC_Time_SampleRates;

uint32_t OSC_Time_Offset;
uint32_t OSC_Time_Scale;
uint32_t OSC_Time_SampleRate;
uint32_t OSC_Time_Period;

// Channel 1 defines

uint32_t OSC_CH1_Offset;
uint32_t OSC_CH1_Scale;

// Channel 2 defines

uint32_t OSC_CH2_Offset;
uint32_t OSC_CH2_Scale;

// Trigger defines

uint32_t OSC_Trigger_Offset;

// Markers defines

uint32_t OSC_Markers_Offset_A;
uint32_t OSC_Markers_Offset_B;
uint32_t OSC_Markers_Time;
uint32_t OSC_Markers_Offset_B;
uint32_t OSC_Markers_Offset_B;

#endif
