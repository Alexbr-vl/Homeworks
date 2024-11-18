#include "Eagle.h"

Eagle::Eagle():Air_transport("Орел", 8, 0.06){}

double Eagle::time_of_distance(double distance) const
{
	double reduced_distance = distance * (1.0 - distance_reduction_factor_);
	return reduced_distance / speed_;
}