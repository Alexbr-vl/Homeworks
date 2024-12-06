#include"Air_transport.h"

Air_transport::Air_transport(const std::string& name, double speed, double distance_reduction_factor)
	: Transport(name, speed), distance_reduction_factor_(distance_reduction_factor) {};

double Air_transport::time_of_distance(double distance) const
{
	double reduced_distance = distance * (1.0 - distance_reduction_factor_);
	return reduced_distance / speed_;
}

bool Air_transport::is_air_transport() const { return true; }
