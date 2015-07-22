// File: gui.h
// Header for: gui.c
// Author: Jaka Kordez

#ifndef OUI_DG
#define OUI_DG

#include "stm32f4xx_hal.h"
#include "WM.h"

#define OUI_GRAPH_BACKGROUND	0x00994539
#define OUI_BAR_BACKGROUND		0x006C2B40

typedef struct {
	uint8_t Buttons;
	int8_t Encoder1;
	int8_t Encoder2;
}UserInput;

typedef struct Element{
	char *Text;
	uint32_t Data;
	uint32_t Data2;
	uint8_t Redraw;
	void(*DrawData)			    	(struct Element * element, uint16_t x, uint16_t y);
	void(*HandleUserInput)		(struct Element * element, UserInput input);
}Element;

typedef struct Component{
	char Identifier;
	uint32_t PrimaryColor;
	uint32_t TextColor;
	uint8_t SelectedElement;
	Element **Elements;

	void(*DrawLabel)					(struct Component * component, uint16_t x, uint16_t y);
	void(*DrawGraph)					(struct Component * component, uint16_t x, uint16_t y);
	void(*DrawData)			    	(struct Component * component);
	void(*HandleUserInput)		(struct Component * component, UserInput input);
}Component;

void OUI_Initialize(void);
void OUI_Draw(void);

void OUI_DrawLabel(struct Component * component, uint16_t x, uint16_t y);
void OUI_DrawElementData(struct Element * element, uint16_t x, uint16_t y);

#endif
