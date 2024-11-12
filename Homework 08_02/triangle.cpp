#include"triangle.h"
#include"error_creating_figure.h"



Triangle::Triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_, int angleC_)
	: Figure(name_, 3), sideA(sideA_), sideB(sideB_), sideC(sideC_), angleA(angleA_), angleB(angleB_), angleC(angleC_)
{
	if (angleA + angleB + angleC != 180)
	{
		throw Incorrect_figure_data("\033[4m" + name_ + "\033[0m" + ": Ошибка создания фигуры: сумма углов не равна 180.\n");
	}
}

void Triangle::print_info() const
{
	Figure::print_info();
	std::cout << "СОЗДАН!" << std::endl;
	std::cout << "Sides: " << "a=" << sideA << ", b=" << sideB << ", c=" << sideC << std::endl;
	std::cout << "Angles: " << "A=" << angleA << ", B=" << angleB << ", C=" << angleC << std::endl;
	std::cout << std::endl;
}