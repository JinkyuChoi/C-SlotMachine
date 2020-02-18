//301024988 Jinkyu Choi
//2020-02-18
//Button to decrease the Betting
//Referenced from Tom Tsiliopoulos

#pragma once
#ifndef __DECREASE_BET_BUTTON__
#define __DECREASE_BET_BUTTON__

#include "Button.h"

class DecreaseBetButton : public Button
{
public:
	DecreaseBetButton();
	~DecreaseBetButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__DECREASE_BET_BUTTON__) */