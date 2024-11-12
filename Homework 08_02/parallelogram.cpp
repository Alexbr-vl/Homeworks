#include"parallelogram.h"

Parallelogram::Parallelogram(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
: Quadrangle(name_, sideA_, sideB_, sideA_, sideB_, angleA_, angleB_, angleA_, angleB_) {}
