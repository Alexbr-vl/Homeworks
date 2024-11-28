#pragma once
#include"rectangle.h"

class Square :public Rectangle
{
public:
	Square(std::string name_, int sideA_);

	virtual bool is_correct() const override;
};