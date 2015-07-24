// File: gui.h
// Header for: gui.c
// Author: Jaka Kordez

#ifndef OUI_DG
#define OUI_DG

#include "stm32f4xx_hal.h"
#include "WM.h"
#include "input.h"

#define OUI_GRAPH_BACKGROUND	0x00994539
#define OUI_GRAPH_LINES				0x00DEACA5
#define OUI_BAR_BACKGROUND		0x006C2B40

#define OUI_BUT_Settings			0x0001

typedef struct Element Element;
struct Element{
	char *Text;
	uint32_t Data;
	uint32_t Data2;
	uint8_t Redraw;
	void(*DrawData)			    	(Element * This, uint16_t x, uint16_t y);
	void(*HandleUserInput)		(Element * This, UserInput input);
};

typedef struct Component Component;
struct Component{
	char Identifier;
	uint32_t PrimaryColor;
	uint32_t TextColor;
	uint8_t SelectedElement;
	Element **Elements;

	void(*DrawLabel)					(Component * This, uint16_t x, uint16_t y);
	void(*DrawGraph)					(Component * This, uint16_t x, uint16_t y);
	void(*DrawData)			    	(Component * This);
	void(*HandleUserInput)		(Component * This, UserInput input);
};

typedef struct UI_MemoryDevice {
		GUI_MEMDEV_Handle DeviceHandle;
		uint16_t Width;
		uint16_t Height;
		uint16_t X;
		uint16_t Y;
}UI_MemoryDevice;

void OUI_Initialize(void);
void OUI_Draw(void);
void OUI_DrawGraph(void);

void OUI_DrawLabel(Component * This, uint16_t x, uint16_t y);
void OUI_DrawElementData(Element * This, uint16_t x, uint16_t y);
void OUI_DrawData(Component * This, uint8_t count);
void UI_CreateMemoryDevice(UI_MemoryDevice *Device, uint16_t x,uint16_t y,uint16_t w, uint16_t h);

extern UI_MemoryDevice OUI_MemoryDeviceGrid;

#endif
