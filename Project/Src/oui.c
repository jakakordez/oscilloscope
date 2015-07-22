// File: gui.c
// Author: Jaka Kordez

#include "oui.h"
#include "time.h"
#include "channels.h"
#include "trigger.h"
#include "markers.h"

Component *OUI_Components[5];

void OUI_Initialize(){
	GUI_SetBkColor(OUI_GRAPH_BACKGROUND);
	GUI_Clear();
	
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
	OUI_DrawGrid();
}

void OUI_DrawLabel(struct Component * component, uint16_t x, uint16_t y){
	GUI_SetColor(component->PrimaryColor);
	GUI_FillCircle(x+15, y+22, 12);
	GUI_RECT dispRect;
	dispRect.x0 = x+3;
	dispRect.y0 = y+10;
	dispRect.x1 = x+27;
	dispRect.y1 = y+34;
	GUI_SetFont(&GUI_Font20_1);
	GUI_SetBkColor(component->PrimaryColor);
	GUI_SetColor(component->TextColor);
	GUI_DispStringInRect(&component->Identifier, &dispRect, GUI_TA_VCENTER | GUI_TA_HCENTER);
}

void OUI_DrawData(struct Component * component, uint8_t count){
	for(int i = 0; i < count; i++){
		component->Elements[i]->DrawData(component->Elements[i], 64*i, 211);
	}
}

void OUI_DrawElementData(struct Element * element, uint16_t x, uint16_t y){
	if(element->Redraw){
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
		GUI_DispStringInRect(element->Text, &dispRect, GUI_TA_TOP | GUI_TA_HCENTER);
		GUI_SetFont(&GUI_Font16_1);
		GUI_DispStringInRect(element->Text, &dispRect, GUI_TA_BOTTOM | GUI_TA_HCENTER);
		element->Redraw = 0;
	}
}

void OUI_DrawGrid(){
	GUI_SetColor(OUI_GRAPH_LINES);
	for(int i = 15; i <= 195; i += 20){
		GUI_DrawLine(40, i, 310, i);
	}
	for(int i = 40; i <= 310; i += 30){
		GUI_DrawLine(i, 15, i, 195);
	}
}

