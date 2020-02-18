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