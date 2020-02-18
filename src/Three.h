//301024988 Jinkyu Choi
//2020-02-18
//Visual Slot for Three
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __THREE__
#define __THREE__
#include "DisplayObject.h"

class Three : public DisplayObject
{
public:

	Three();
	~Three();

	void draw() override;
	void update() override;
	void clean() override;

};

#endif /* defined (__THREE__) */