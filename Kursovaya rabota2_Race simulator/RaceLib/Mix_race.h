#pragma once
#include "Race.h"

class Mix_race :public Race
{
	using Race::Race;
	void add_participant(Transport* transport) override;
};