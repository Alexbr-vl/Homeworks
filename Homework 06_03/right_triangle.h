#pragma once
#include"triangle.h"

class Right_triangle : public Triangle
{
public:
	Right_triangle(std::string name_, int sideA_, int sideB_, int sideC_, int angleB_, int angleC_);
	virtual bool is_correct() const override;
};