#pragma once
#ifndef __SLOT__
#define __SLOT__
#include "DisplayObject.h"

class Slot : DisplayObject
{
public:

	Slot();
	~Slot();
	
	void draw() override;
	void update() override;
	void clean() override;

private:
	void Change();
};



#endif /* defined (__START_BUTTON__) */
