#include"figure.h"


Figure::Figure() : name("Unknown figure"), sides_count(0) {}
Figure::Figure(std::string name_, int sides_count_) :name(name_), sides_count(sides_count_) {}

bool  Figure::is_correct() const { return sides_count == 0;}
void Figure::print_info()
{
	std::cout << "\033[4m" << name << "\033[0m" << ":" << std::endl << "number of sides: " << sides_count << std::endl;
	std::cout << (is_correct() ? "Correct" : "Incorrect") << std::endl;
}
