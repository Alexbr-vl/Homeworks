#include"isosceles_triangle.h"

Isosceles_triangle::Isosceles_triangle(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
: Triangle(name_, sideA_, sideB_, sideA_, angleA_, angleB_, angleA_) {}
bool Isosceles_triangle::is_correct() const { return Triangle::is_correct() && sideA == sideC && angleA == angleC; }
