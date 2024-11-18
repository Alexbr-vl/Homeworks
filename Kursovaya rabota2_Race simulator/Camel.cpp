#include"Camel.h"


Camel::Camel():Ground_transport("Верблюд", 10, 30,5) {}

double Camel::time_of_distance(double distance) const
{
	int total_of_stops = 0;
	double time_to_move = distance / speed_;
	total_of_stops = (int)(time_to_move / time_before_rest_);

	if (total_of_stops == 1) { return time_to_move + total_of_stops * time_to_rest_; }

	if (total_of_stops > 1) { return time_to_move + time_to_rest_ + (total_of_stops - 1) * 8; }
}
