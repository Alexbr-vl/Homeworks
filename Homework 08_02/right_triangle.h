#pragma once
#include"triangle.h"

class Right_triangle : public Triangle
{
public:
	Right_triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_);
};