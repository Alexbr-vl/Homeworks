#pragma once
#include"triangle.h"
#include"error_creating_figure.h"

class Isosceles_triangle :public Triangle
{
public:
	Isosceles_triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_);
};