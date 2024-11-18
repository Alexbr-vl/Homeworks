#include"All_terrain_boots.h"


All_terrain_boots::All_terrain_boots() :Ground_transport("Ботинки - вездеходы",6, 60, 10) {};
double All_terrain_boots::time_of_distance(double distance) const
{
	int total_of_stops = 0;
	double time_to_move = distance / speed_;
	total_of_stops = (int)(time_to_move / time_before_rest_);

	if (total_of_stops <= 1) { return time_to_move + total_of_stops * time_to_rest_; }

	if (total_of_stops >= 2) { return time_to_move + time_to_rest_ + (total_of_stops-1)*5; }
}