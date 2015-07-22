// File: markers.c
// Author: Jaka Kordez

#include "markers.h"

void Markers_DrawGraph(struct Component * component, uint16_t x, uint16_t y);
void Markers_DrawData(struct Component * component);
void Markers_HandleUserInput(struct Component * component, UserInput input);

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

void Markers_DrawGraph(struct Component * component, uint16_t x, uint16_t y){
	
	
}

void Markers_DrawData(struct Component * component){
	OUI_DrawData(component, 4);
}

void Markers_HandleUserInput(struct Component * component, UserInput input){
	if(component->Elements[0]->Data > 0 || input.Encoder1 > 0){
		component->Elements[0]->Data += input.Encoder1;
		component->Elements[0]->Redraw = 1;
	}
	if((component->Elements[1]->Data > 0 || input.Encoder1 > 0)&& component->SelectedElement > 0){
		component->Elements[1]->Data += input.Encoder2;
		component->Elements[1]->Redraw = 1;
	}
}

Component *GetMarkers()
{
	return &Markers;
}

