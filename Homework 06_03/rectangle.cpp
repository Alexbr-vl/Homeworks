#include"rectangle.h"

Rectangle::Rectangle(std::string name_, int sideA_, int sideB_)
: Parallelogram(name_, sideA_, sideB_, 90, 90) {}

bool Rectangle::is_correct() const { return Parallelogram::is_correct() && (angleA == angleB == angleC == angleD) == 90; }