#pragma once
#include "Race.h"

class Air_race :public Race  //создаем класс воздушных гонок
{
	using Race::Race;
	void add_participant(Transport* transport) override;
};