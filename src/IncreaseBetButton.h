//301024988 Jinkyu Choi
//2020-02-18
//Button to add the Betting
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __INCREASE_BET_BUTTON__
#define __INCREASE_BET_BUTTON__

#include "Button.h"

class IncreaseBetButton : public Button
{
public:
	IncreaseBetButton();
	~IncreaseBetButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__INCREASE_BET_BUTTON__) */