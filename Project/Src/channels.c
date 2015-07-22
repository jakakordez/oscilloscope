// File: channels.c
// Author: Jaka Kordez

#include "channels.h"

void Channel_DrawGraph(struct Component * component, uint16_t x, uint16_t y);
void Channel_DrawData(struct Component * component);
void Channel_HandleUserInput(struct Component * component, UserInput input);

// --------------------------------------------------------------------		Channel 1 structure 

Element Channel1_Offset = {"Offset", 0, 0, 1, OUI_DrawElementData};
Element Channel1_Scale = {"Scale", 0, 0, 1, OUI_DrawElementData};
Element *Channel1_Elements[2] = {
	&Channel1_Offset,
	&Channel1_Scale
};

Component Channel1 = {
	'1',
	GUI_RED,
	GUI_WHITE,
	0,
	Channel1_Elements,
	OUI_DrawLabel,
	Channel_DrawGraph,
	Channel_DrawData,
	Channel_HandleUserInput
};

// --------------------------------------------------------------------		Channel 2 structure 
Element Channel2_Offset = {"Offset", 0, 0, 1, OUI_DrawElementData};
Element Channel2_Scale = {"Scale", 0, 0, 1, OUI_DrawElementData};
Element *Channel2_Elements[2] = {
	&Channel2_Offset,
	&Channel2_Scale
};

Component Channel2 = {
	'2',
	GUI_GREEN,
	GUI_BLACK,
	0,
	Channel2_Elements,
	OUI_DrawLabel,
	Channel_DrawGraph,
	Channel_DrawData,
	Channel_HandleUserInput
};

void Channel_DrawGraph(struct Component * component, uint16_t x, uint16_t y){
	
	
}

void Channel_DrawData(struct Component * component){
	component->Elements[0]->DrawData(component->Elements[0], 0, 211);
	component->Elements[1]->DrawData(component->Elements[1], 65, 211);
}

void Channel_HandleUserInput(struct Component * component, UserInput input){
	if(component->Elements[0]->Data > 0 || input.Encoder1 > 0){
		component->Elements[0]->Data += input.Encoder1;
		component->Elements[0]->Redraw = 1;
	}
	if(component->Elements[1]->Data > 0 || input.Encoder1 > 0){
		component->Elements[1]->Data += input.Encoder2;
		component->Elements[1]->Redraw = 1;
	}
}

Component *GetChannel1()
{
	return &Channel1;
}


Component *GetChannel2(){
	return &Channel2;
}
