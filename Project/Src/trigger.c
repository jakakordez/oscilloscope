// File: trigger.c
// Author: Jaka Kordez

#include "trigger.h"

void Trigger_DrawData(Component * This);
void Trigger_HandleUserInput(Component * This, UserInput input);

// --------------------------------------------------------------------		Time structure 

Element Trigger_Offset = {"Offset", 0, 0, 1, OUI_DrawElementData};
Element *Trigger_Elements[1] = {
	&Trigger_Offset,
};

Component Trigger = {
	'T',
	GUI_YELLOW,
	GUI_BLACK,
	0,
	Trigger_Elements,
	OUI_DrawLabel,
	NULL,
	Trigger_DrawData,
	Trigger_HandleUserInput
};


void Trigger_DrawData(Component * This){
	OUI_DrawData(This, 1);
}

void Trigger_HandleUserInput(Component * This, UserInput input){
	if(This->Elements[0]->Data > 0 || input.Encoder1 > 0){
		This->Elements[0]->Data += input.Encoder1;
		This->Elements[0]->Redraw = 1;
	}
}

Component *GetTrigger()
{
	return &Trigger;
}

