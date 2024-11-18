#include "Broomstick.h"

Broomstick::Broomstick():Air_transport("Метла", 20, 0){}

double Broomstick::time_of_distance(double distance) const
{
	if (distance < 1000) { return (distance / speed_); }
	if (distance >= 1000)
	{
		double distance_reduction_factor = 0.01 * (int)(distance/1000);
		double reduced_distance = distance * (1.0 - distance_reduction_factor);
		return reduced_distance / speed_;
	}
}