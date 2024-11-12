#pragma once
#include"figure.h"


class Quadrangle :public Figure
{
protected:
	int sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD;
public:
	Quadrangle(std::string name_, int sideA_, int sideB_, int sideC_, int sideD_, int angleA_, int angleB_, int angleC_, int angleD_);
	virtual void print_info() override;
};