#pragma once
#include"figure.h"

class Triangle :public Figure
{
protected:
	int sideA, sideB, sideC, angleA, angleB, angleC;
public:
	Triangle(const std::string& name_, int sideA_, int sideB_, int sideC_, int angleA_, int angleB_, int angleC_);
	virtual void print_info() const override;
};