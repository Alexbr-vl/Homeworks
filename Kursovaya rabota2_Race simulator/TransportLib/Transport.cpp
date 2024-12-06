#include "Transport.h"

Transport::Transport(const std::string& name, double speed)
		  :name_(name), speed_(speed) {};
std::string Transport::get_name() const { return name_; }

bool Transport::is_ground_transport() const { return false; }
bool Transport::is_air_transport() const { return false; }