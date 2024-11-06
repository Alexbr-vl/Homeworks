#include"square.h"


Square::Square(std::string name_, int sideA_)
:Rectangle(name_, sideA_, sideA_) {}

bool Square::is_correct() const { return Rectangle::is_correct() && (sideA == sideB == sideC == sideD); }