#include"quadrangle.h"

Quadrangle::Quadrangle(std::string name_, int sideA_, int sideB_, int sideC_, int sideD_, int angleA_, int angleB_, int angleC_, int angleD_) 
: Figure(name_, 4), sideA(sideA_), sideB(sideB_), sideC(sideC_), sideD(sideD_), angleA(angleA_), angleB(angleB_), angleC(angleC_), angleD(angleD_) {}

bool Quadrangle::is_correct() const { return sides_count == 4 && (angleA + angleB + angleC) == 360; }
void Quadrangle::print_info() 
{
	std::cout << std::endl;
	Figure::print_info();
	std::cout << "Sides: " << "a=" << sideA << ", b=" << sideB << ", c=" << sideC << ", d=" << sideD << std::endl;
	std::cout << "Angles: " << "A=" << angleA << ", B=" << angleB << ", C=" << angleC << ", D=" << angleD << std::endl;
}