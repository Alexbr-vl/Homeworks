#include"right_triangle.h"

Right_triangle::Right_triangle(std::string name_, int sideA_, int sideB_, int sideC_, int angleB_, int angleC_)
: Triangle(name_, sideA_, sideB_, sideC_, 90, angleB_, angleC_) {}
bool Right_triangle::is_correct() const { return Triangle::is_correct() && angleC == 90; }
