#include"figure.h"
#include"triangle.h"
#include"right_triangle.h"
#include"isosceles_triangle.h"
#include"error_creating_figure.h"
#include<Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	try
	{
		Triangle triangle("Треугольник", 10, 20, 30, 60, 70, 60);
		triangle.print_info();
	}
	catch (const Incorrect_figure_data& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Right_triangle right_triangle("Прямоугольный треугольник", 10, 20, 30, 30, 60);
		right_triangle.print_info();
	}
	catch (const Incorrect_figure_data& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Isosceles_triangle isosceles_triangle("Равнобедренный треугольник", 23,44,13,60,60);
		isosceles_triangle.print_info();
	}
	catch (const Incorrect_figure_data& e)
	{
		std::cout << e.what() << std::endl;
	}
}