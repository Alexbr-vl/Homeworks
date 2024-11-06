#pragma once
#include"triangle.h"

class Equilateral_triangle :public Triangle
{
public:
	Equilateral_triangle(std::string name_, int sideA_);
	virtual bool is_correct() const override;
};