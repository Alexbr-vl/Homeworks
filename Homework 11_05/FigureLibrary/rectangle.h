#pragma once
#include "parallelogram.h"

class Rectangle :public Parallelogram
{
public:
	Rectangle(std::string name_, int sideA_, int sideB_);

	virtual bool is_correct() const override;
};