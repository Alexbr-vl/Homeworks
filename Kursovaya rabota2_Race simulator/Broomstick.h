#pragma once
#include "Air_transport.h"

class Broomstick :public Air_transport
{
public:
	Broomstick();
	double time_of_distance(double distance) const override;
};