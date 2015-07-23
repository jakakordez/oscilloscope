// File: time.c
// Author: Jaka Kordez

#include "time.h"

void Time_DrawData(Component * This);
void Time_HandleUserInput(Component * This, UserInput input);

// --------------------------------------------------------------------		Time structure 

Element Time_Offset = {"Offset", 0, 0, 1, OUI_DrawElementData};
Element Time_Scale = {"Scale", 1, 0, 1, OUI_DrawElementData};
Element Time_SampleRate = {"Sample r.", 1000000, 0, 1, OUI_DrawElementData};
Element Time_Period = {"Period", 100, 0, 1, OUI_DrawElementData};
Element *Time_Elements[4] = {
	&Time_Offset,
	&Time_Scale,
	&Time_SampleRate,
	&Time_Period
};

Component Time = {
	'C',
	GUI_WHITE,
	GUI_BLACK,
	0,
	Time_Elements,
	OUI_DrawLabel,
	NULL,
	Time_DrawData,
	Time_HandleUserInput
};


void Time_DrawData(Component * This){
	OUI_DrawData(This, 4);
}

void Time_HandleUserInput(Component * This, UserInput input){
	if(This->Elements[0]->Data > 0 || input.Encoder1 > 0){
		This->Elements[0]->Data += input.Encoder1;
		This->Elements[0]->Redraw = 1;
	}
	if(input.Buttons & OUI_BUT_Settings){
		This->SelectedElement = (This->SelectedElement + 1)%2;
	}
	if((This->Elements[1]->Data > 0 || input.Encoder1 > 0)&& This->SelectedElement == 0){
		This->Elements[1]->Data += input.Encoder2;
		This->Elements[1]->Redraw = 1;
	}
}

Component *GetTime()
{
	return &Time;
}

