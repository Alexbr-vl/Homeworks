#pragma once
#include"Ground_transport.h"

class Camel :public Ground_transport
{
public:
	Camel();
	double time_of_distance(double distance) const override;
};