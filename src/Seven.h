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