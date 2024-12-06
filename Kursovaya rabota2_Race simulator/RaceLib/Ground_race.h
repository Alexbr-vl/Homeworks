#pragma once
#include "Race.h"

class Ground_race : public Race
{
	using Race::Race;
	void add_participant(Transport* transport) override;
};

