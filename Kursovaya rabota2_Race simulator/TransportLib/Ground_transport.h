#pragma once
#include "Transport.h"
#include <cmath>

class Ground_transport :public Transport
{
protected:
	double time_before_rest_;
	double time_to_rest_;
public:
	Ground_transport(const std::string& name, double speed, double time_before_rest, double time_to_rest);
	double time_of_distance(double distance) const override = 0;

	// Этот транспорт наземный
	bool is_ground_transport() const override;
};