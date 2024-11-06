#pragma once
#include"triangle.h"

class Isosceles_triangle :public Triangle
{
public:
	Isosceles_triangle(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_);
	virtual bool is_correct() const override;
};