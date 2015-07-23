// File: markers.c
// Author: Jaka Kordez

#include "markers.h"

void Markers_DrawGraph(Component * This, uint16_t x, uint16_t y);
void Markers_DrawData(Component * This);
void Markers_HandleUserInput(Component * This, UserInput input);

// --------------------------------------------------------------------		Time structure 

Element Markers_Offset		= {"Offset", 0, 0, 1, OUI_DrawElementData};
Element Markers_Time 			= {"Time", 0, 0, 1, OUI_DrawElementData};
Element Markers_Voltage 	= {"Frequency", 0, 0, 1, OUI_DrawElementData};
Element Markers_Frequency = {"Voltage", 0, 0, 1, OUI_DrawElementData};
Element *Markers_Elements[4] = {
	&Markers_Offset,
	&Markers_Time,
	&Markers_Voltage,
	&Markers_Frequency
};

Component Markers = {
	'M',
	GUI_ORANGE,
	GUI_BLACK,
	0,
	Markers_Elements,
	OUI_DrawLabel,
	Markers_DrawGraph,
	Markers_DrawData,
	Markers_HandleUserInput
};

void Markers_DrawGraph(Component * This, uint16_t x, uint16_t y){
	
	
}

void Markers_DrawData(Component * This){
	OUI_DrawData(This, 4);
}

void Markers_HandleUserInput(Component * This, UserInput input){
	if(This->Elements[0]->Data > 0 || input.Encoder1 > 0){
		This->Elements[0]->Data += input.Encoder1;
		This->Elements[0]->Redraw = 1;
	}
	if((This->Elements[1]->Data > 0 || input.Encoder1 > 0)&& This->SelectedElement > 0){
		This->Elements[1]->Data += input.Encoder2;
		This->Elements[1]->Redraw = 1;
	}
}

Component *GetMarkers()
{
	return &Markers;
}

