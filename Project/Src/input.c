// File: input.c
// Author: Jaka Kordez

#include "input.h"

UserInput PreviousInput;

UserInput GetUserInput(void){
	return PreviousInput;
}
