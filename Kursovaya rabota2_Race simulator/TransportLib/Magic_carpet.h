#pragma once
#include "Air_transport.h"

class Magic_carpet :public Air_transport
{
public:
	Magic_carpet();
	double time_of_distance(double distance) const override;
};