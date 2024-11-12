#include"isosceles_triangle.h"
#include"error_creating_figure.h"

Isosceles_triangle::Isosceles_triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_)
: Triangle(name_, sideA_, sideB_, sideC_, angleA_, angleB_, angleA_) 
{
	if (sideA != sideC || angleA != angleC)
	{
		throw Incorrect_figure_data("\033[4m" + name_ + "\033[0m" + ": Ошибка создания фигуры: Углы А и С или стороны А и С не равны\n");
	}
}
