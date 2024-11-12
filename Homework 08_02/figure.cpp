#include"figure.h"

Figure::Figure() : name("Unknown figure"), sides_count(0) {}
Figure::Figure(const std::string& name_, int sides_count_) :name(name_), sides_count(sides_count_) {}


void Figure::print_info() const
{
	std::cout << "\033[4m" << name << "\033[0m" << ":";
}
