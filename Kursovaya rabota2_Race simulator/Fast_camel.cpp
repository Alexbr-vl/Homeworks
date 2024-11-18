#include"Fast_camel.h"

Fast_camel::Fast_camel() :Ground_transport("Верблюд-быстроход", 40, 10, 5) {}

double Fast_camel::time_of_distance(double distance) const
{
	int total_of_stops = 0;
	double time_to_move = distance / speed_;
	total_of_stops = (int)(time_to_move / time_before_rest_);

	if (total_of_stops == 1) { return time_to_move + total_of_stops * time_to_rest_; }

	if (total_of_stops == 2) { return time_to_move + time_to_rest_ + 6,5 ; }

	if (total_of_stops > 2) { return time_to_move + time_to_rest_ + 6, 5 + (total_of_stops - 2) * 8; }
}
