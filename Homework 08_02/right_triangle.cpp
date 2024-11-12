#include"right_triangle.h"
#include"error_creating_figure.h"

Right_triangle::Right_triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_)
: Triangle(name_, sideA_, sideB_, sideC_, angleA_, angleB_,90 ) 
{
	if (angleC != 90)
	{
		throw Incorrect_figure_data("\033[4m" + name_ + "\033[0m" + ": Ошибка создания фигуры: сумма углов в прямоугольном треугольнике должна быть равна 180 и угол C должен быть 90.\n");
	}
}

