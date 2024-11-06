#include"equilateral_triangle.h"

Equilateral_triangle::Equilateral_triangle(std::string name_, int sideA_)
: Triangle(name_, sideA_, sideA_, sideA_, 60, 60, 60) {}
bool Equilateral_triangle::is_correct() const { return Triangle::is_correct() && sideA == sideB == sideC && (angleA == angleB == angleC) == 60; }
