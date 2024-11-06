#include"triangle.h"


Triangle::Triangle(std::string name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_, int angleC_)
: Figure(name_, 3), sideA(sideA_), sideB(sideB_), sideC(sideC_), angleA(angleA_), angleB(angleB_), angleC(angleC_) {}

bool Triangle::is_correct() const { return sides_count == 3 && (angleA + angleB + angleC == 180); }
void Triangle::print_info()
{
	std::cout << std::endl;
	Figure::print_info();
	std::cout << "Sides: " << "a=" << sideA << ", b=" << sideB << ", c=" << sideC << std::endl;
	std::cout << "Angles: " << "A=" << angleA << ", B=" << angleB << ", C=" << angleC << std::endl;
}