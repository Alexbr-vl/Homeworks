#pragma once
#include"Ground_transport.h"

class All_terrain_boots :public Ground_transport
{
public:
	All_terrain_boots();
	double time_of_distance(double distance) const override;
};