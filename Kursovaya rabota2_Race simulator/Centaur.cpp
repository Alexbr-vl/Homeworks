#include "Centaur.h"

Centaur::Centaur() :Ground_transport("Кентавр", 15, 8, 2) {}

double Centaur::time_of_distance(double distance) const
{
	int total_of_stops = 0;
	double time_to_move = distance / speed_;
	total_of_stops = (int)(time_to_move / time_before_rest_);
	double total_rest_time = total_of_stops * time_to_rest_;
	return time_to_move + total_rest_time;
}