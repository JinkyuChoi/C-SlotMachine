//301024988 Jinkyu Choi
//2020-02-18
//Visual Slot for Seven
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __SEVEN__
#define __SEVEN__
#include "DisplayObject.h"

class Seven : public DisplayObject
{
public:

	Seven();
	~Seven();

	void draw() override;
	void update() override;
	void clean() override;

};

#endif /* defined (__SEVEN__) */