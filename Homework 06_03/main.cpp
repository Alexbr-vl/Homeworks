#include"figure.h"
#include"triangle.h"
#include"right_triangle.h"
#include"isosceles_triangle.h"
#include"equilateral_triangle.h"
#include"quadrangle.h"
#include"parallelogram.h"
#include"rectangle.h"
#include"rhomb.h"
#include"square.h"

int main()
{
	Figure figure;
	Triangle triangle("Triangle", 10, 20, 30, 50, 60, 70);
	Right_triangle right_triangle("Right-triangle", 10, 20, 30, 50, 60);
	Isosceles_triangle isosceles_triangle("Isosceles_triangle", 10, 20, 50, 60);
	Equilateral_triangle equilateral_triangle("Equilateral_triangle", 30);
	Quadrangle quadrangle("Quadrangle", 10, 20, 30, 40, 50, 60, 70, 80);
	Parallelogram parallelogram("Parallelogram", 20, 30, 30, 40);
	Rectangle rectangle("Rectangle", 10, 20);
	Rhomb rhomb("Rhomb", 30, 30, 40);
	Square square("Square", 20);

	figure.print_info();
	triangle.print_info();
	right_triangle.print_info();
	isosceles_triangle.print_info();
	equilateral_triangle.print_info();
	quadrangle.print_info();
	parallelogram.print_info();
	rectangle.print_info();
	rhomb.print_info();
	square.print_info();
}