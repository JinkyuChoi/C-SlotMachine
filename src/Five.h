#pragma once
#ifndef __FIVE__
#define __FIVE__
#include "DisplayObject.h"

class Five : public DisplayObject
{
public:

	Five();
	~Five();

	void draw() override;
	void update() override;
	void clean() override;

};

#endif /* defined (__FIVE__) */