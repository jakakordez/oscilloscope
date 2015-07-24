// File: gui.c
// Author: Jaka Kordez

#include "oui.h"
#include "time.h"
#include "channels.h"
#include "trigger.h"
#include "markers.h"

Component *OUI_Components[5];
UI_MemoryDevice OUI_MemoryDeviceGrid = { 0 };

void OUI_Initialize(){
	GUI_SetBkColor(OUI_GRAPH_BACKGROUND);
	GUI_Clear();
	
	UI_CreateMemoryDevice(&OUI_MemoryDeviceGrid, 40, 15, 270, 180);
	
	OUI_Components[0] = GetTime();
	OUI_Components[1] = GetChannel1();
	OUI_Components[2] = GetChannel2();
	OUI_Components[3] = GetTrigger();
	OUI_Components[4] = GetMarkers();
	
	for(int i = 0; i < 5; i++){
		OUI_Components[i]->DrawLabel(OUI_Components[i], 0, i*42);
	}
}

void OUI_Draw(){
	OUI_Components[0]->DrawData(OUI_Components[0]);
	OUI_DrawGraph();
}

void OUI_DrawLabel(Component * This, uint16_t x, uint16_t y){
	GUI_SetColor(This->PrimaryColor);
	GUI_FillCircle(x+15, y+22, 12);
	GUI_RECT dispRect;
	dispRect.x0 = x+3;
	dispRect.y0 = y+10;
	dispRect.x1 = x+27;
	dispRect.y1 = y+34;
	GUI_SetFont(&GUI_Font20_1);
	GUI_SetBkColor(This->PrimaryColor);
	GUI_SetColor(This->TextColor);
	GUI_DispStringInRect(&This->Identifier, &dispRect, GUI_TA_VCENTER | GUI_TA_HCENTER);
}

void OUI_DrawData(Component * This, uint8_t count){
	for(int i = 0; i < count; i++){
		This->Elements[i]->DrawData(This->Elements[i], 64*i, 211);
	}
}

void UI_CreateMemoryDevice(UI_MemoryDevice *Device, uint16_t x,uint16_t y,uint16_t w, uint16_t h)
{ 
	Device->X = x;
	Device->Y = y;
	Device->Width = w;
	Device->Height = h;
	Device->DeviceHandle = GUI_MEMDEV_CreateEx(0, 0, Device->Width, Device->Height,GUI_MEMDEV_NOTRANS);
}

void OUI_DrawElementData(Element * This, uint16_t x, uint16_t y){
	if(This->Redraw){
		GUI_SetColor(OUI_BAR_BACKGROUND);
		GUI_FillRect(x, y, x+62, y+29);
		GUI_SetBkColor(OUI_BAR_BACKGROUND);
		GUI_SetColor(GUI_WHITE);
		GUI_RECT dispRect;
		dispRect.x0 = x+1;
		dispRect.y0 = y+1;
		dispRect.x1 = x+62;
		dispRect.y1 = y+28;
		GUI_SetFont(&GUI_Font8_1);
		GUI_DispStringInRect(This->Text, &dispRect, GUI_TA_TOP | GUI_TA_HCENTER);
		GUI_SetFont(&GUI_Font16_1);
		GUI_DispStringInRect(This->Text, &dispRect, GUI_TA_BOTTOM | GUI_TA_HCENTER);
		This->Redraw = 0;
	}
}

void OUI_DrawGraph(){	
	GUI_MEMDEV_Select(OUI_MemoryDeviceGrid.DeviceHandle);
	GUI_SetBkColor(OUI_GRAPH_BACKGROUND);
	GUI_Clear();
	
	GUI_SetColor(OUI_GRAPH_LINES);
	for(int i = 0; i <= 180; i += 20){
		GUI_DrawLine(0, i, 270, i);
	}
	for(int i = 0; i <= 270; i += 30){
		GUI_DrawLine(i, 0, i, 180);
	}
	
	OUI_Components[2]->DrawGraph(OUI_Components[1], 0, 0);
	OUI_Components[1]->DrawGraph(OUI_Components[1], 0, 0);
	
	GUI_MEMDEV_CopyToLCDAt(OUI_MemoryDeviceGrid.DeviceHandle,OUI_MemoryDeviceGrid.X,OUI_MemoryDeviceGrid.Y);
	GUI_MEMDEV_Clear(OUI_MemoryDeviceGrid.DeviceHandle);
}

