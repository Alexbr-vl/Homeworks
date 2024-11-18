#pragma once
#include "Transport.h"

class Air_transport :public Transport
{
protected:
	double distance_reduction_factor_;
	
public:
	Air_transport(const std::string& name, double speed, double distance_reduction_factor);
	double time_of_distance(double distance) const override = 0;
};