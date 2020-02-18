#pragma once
#ifndef __BET_BUTTON__
#define __BET_BUTTON__

#include "Button.h"

class BetButton : public Button
{
public:
	BetButton();
	~BetButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__BET_BUTTON__) */