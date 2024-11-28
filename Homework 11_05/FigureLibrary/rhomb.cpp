#include"rhomb.h"


Rhomb::Rhomb(std::string name_, int sideA_, int angleA_, int angleB_)
:Parallelogram(name_, sideA_, sideA_, angleA_, angleB_) {}

bool Rhomb::is_correct() const { return Parallelogram::is_correct() && angleA == angleC && angleB == angleD; }