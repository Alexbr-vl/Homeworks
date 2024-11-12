#pragma once
#include"quadrangle.h"

class  Parallelogram :public Quadrangle
{
public:
	Parallelogram(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_);
};