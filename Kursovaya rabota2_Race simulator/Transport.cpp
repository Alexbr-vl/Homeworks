#include "Transport.h"

Transport::Transport(const std::string& name, double speed)
		  :name_(name), speed_(speed) {};
std::string Transport::get_name() const { return name_; }
