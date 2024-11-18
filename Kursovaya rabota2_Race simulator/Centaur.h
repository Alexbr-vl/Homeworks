#pragma once
#include "Ground_transport.h"

class Centaur :public Ground_transport
{
public:
	Centaur();
	double time_of_distance(double distance) const override;
};