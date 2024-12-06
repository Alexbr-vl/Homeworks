#include "Magic_carpet.h"

Magic_carpet::Magic_carpet() :Air_transport("Ковёр-самолёт", 10, 0){}

double Magic_carpet::time_of_distance(double distance) const
{
	if (distance < 1000) { return (distance / speed_); }
	if (distance < 5000) 
	{
		double distance_reduction_factor = 0.03;
		double reduced_distance = distance * (1.0 - distance_reduction_factor);
		return reduced_distance / speed_;
	}
	if (distance < 10000)
	{
		double distance_reduction_factor = 0.1;
		double reduced_distance = distance * (1.0 - distance_reduction_factor);
		return reduced_distance / speed_;
	}
	if (distance >= 10000)
	{
		double distance_reduction_factor = 0.05;
		double reduced_distance = distance * (1.0 - distance_reduction_factor);
		return reduced_distance / speed_;
	}
}