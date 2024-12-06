#pragma once
#include "Air_transport.h"

class Eagle :public Air_transport
{
public:
	Eagle();
	double time_of_distance(double distance) const override;
};