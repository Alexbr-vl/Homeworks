#include "Ground_transport.h"

Ground_transport::Ground_transport(const std::string& name, double speed, double time_before_rest, double time_to_rest)
		:Transport(name, speed), time_before_rest_(time_before_rest), time_to_rest_(time_to_rest) {}
	double Ground_transport::time_of_distance(double distance) const
	{
		int total_of_stops = 0;
		double time_to_move = distance / speed_;
		total_of_stops = (int)(time_to_move / time_before_rest_);
		double total_rest_time = total_of_stops * time_to_rest_;
		return time_to_move + total_rest_time;
	}