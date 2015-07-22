// File: gui.c
// Author: Jaka Kordez

#include "oui.h"
#include "channels.h"

Component *OUI_Components[5];

void OUI_Initialize(){
	GUI_SetBkColor(OUI_GRAPH_BACKGROUND);
	GUI_Clear();
	
	OUI_Components[0] = GetChannel1();
	OUI_Components[1] = GetChannel2();
	
	OUI_Components[0]->DrawLabel(OUI_Components[0], 0, 0);
	OUI_Components[1]->DrawLabel(OUI_Components[1], 0, 60);
}

void OUI_Draw(){
	OUI_Components[0]->DrawData(OUI_Components[0]);
	OUI_Components[1]->DrawData(OUI_Components[1]);
}

void OUI_DrawLabel(struct Component * component, uint16_t x, uint16_t y){
	GUI_SetFont(&GUI_Font20_1);
	GUI_SetColor(component->PrimaryColor);
	GUI_FillCircle(x+15, y+22, 13);
	GUI_SetBkColor(component->PrimaryColor);
	GUI_SetColor(component->TextColor);
	GUI_DispStringAt(&component->Identifier, x+10, y+13);
}

void OUI_DrawElementData(struct Element * element, uint16_t x, uint16_t y){
	if(element->Redraw){
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

