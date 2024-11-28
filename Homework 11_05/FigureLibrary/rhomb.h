#pragma once
#include "parallelogram.h"


class Rhomb :public Parallelogram
{
public:
	Rhomb(std::string name_, int sideA_, int angleA_, int angleB_);

	virtual bool is_correct() const override;
};