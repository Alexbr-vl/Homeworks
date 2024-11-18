#pragma once
#include"Ground_transport.h"

class Fast_camel :public Ground_transport
{
public:
	Fast_camel();
	double time_of_distance(double distance) const override;
};