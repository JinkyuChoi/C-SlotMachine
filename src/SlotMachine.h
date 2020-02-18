//301024988 Jinkyu Choi
//2020-02-18
//Visual Frame for the Slots
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __SLOT_MACHINE__
#define __SLOT_MACHINE__
#include "DisplayObject.h"

class SlotMachine : DisplayObject
{
public:

	SlotMachine();
	~SlotMachine();
	
	void draw() override;
	void update() override;
	void clean() override;
	
};

#endif /* defined (__SLOT_MACHINE__) */