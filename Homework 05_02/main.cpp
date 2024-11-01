#include <iostream>
#include <string>

class Figure
{
public:
	virtual std::string get_side() = 0 ;
	virtual std::string get_angle() = 0;
	virtual std::string get_name() = 0;
	virtual void print_info() = 0;
};

class Triangle:public Figure
{
private:
	int sideA, sideB, sideC;
	int angleA, angleB, angleC;
	std::string name;
public:
	Triangle(std::string name_, int sideA_,int sideB_,int sideC_, int angleA_, int angleB_, int angleC_)
		:name(name_), sideA(sideA_), sideB(sideB_), sideC(sideC_), angleA(angleA_), angleB(angleB_), angleC(angleC_){}

	std::string get_side()
	{
		return "a=" + std::to_string(sideA) + ", " + "b=" + std::to_string(sideB) + ", " "c=" + std::to_string(sideC);
	}
	std::string get_angle()
	{
		return "A=" + std::to_string(angleA) + ", " + "B=" + std::to_string(angleB) + ", " "C=" + std::to_string(angleC);
	}
	std::string get_name()
	{
		return name;
	}
	void print_info() {
		std::cout << get_name() << ":" << std::endl;
		std::cout << "Sides: " << get_side() << std::endl;
		std::cout << "Angles: " << get_angle() << std::endl;
		std::cout << std::endl;
	}
};

class Right_triangle: public Triangle
{
public:
	Right_triangle(std::string name_, int sideA_, int sideB_, int sideC_, int angleB_, int angleC_)
					:Triangle (name_, sideA_, sideB_, sideC_, 90, angleB_, angleC_) {}
};
class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
		:Triangle(name_, sideA_, sideB_, sideA_, angleA_, angleB_, angleA_) {}
};
class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle(std::string name_, int sideA_)
		:Triangle(name_, sideA_, sideA_, sideA_, 60, 60, 60) {}
};

class Quadrangle:public Figure
{
private:
	int sideA, sideB, sideC, sideD;
	int angleA, angleB, angleC, angleD;
	std::string name;
public:
	Quadrangle(std::string name_, int sideA_, int sideB_, int sideC_, int sideD_, int angleA_, int angleB_, int angleC_, int angleD_)
		:name(name_), sideA(sideA_), sideB(sideB_), sideC(sideC_), sideD(sideD_), angleA(angleA_), angleB(angleB_), angleC(angleC_), angleD(angleD_) {}

	std::string get_side()
	{
		return "a=" + std::to_string(sideA) + ", " + "b=" + std::to_string(sideB) + ", " "c=" + std::to_string(sideC) + ", " "d=" + std::to_string(sideD);
	}
	std::string get_angle()
	{
		return "A=" + std::to_string(angleA) + ", " + "B=" + std::to_string(angleB) + ", " "C=" + std::to_string(angleC) + ", " "D=" + std::to_string(angleD);
	}
	std::string get_name()
	{
		return name;
	}
	void print_info() {
		std::cout << get_name() << ":" << std::endl;
		std::cout << "Sides: " << get_side() << std::endl;
		std::cout << "Angles: " << get_angle() << std::endl;
		std::cout << std::endl;
	}
};
class Parallelogram :public Quadrangle
{
public:
	Parallelogram(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
		:Quadrangle(name_, sideA_, sideB_, sideA_, sideB_, angleA_, angleB_, angleA_, angleB_) {}
};
class Rectangle:public Parallelogram
{
public:
	Rectangle(std::string name_, int sideA_, int sideB_)
		:Parallelogram ( name_, sideA_, sideB_, 90, 90) {}
};
class Square :public Rectangle
{
public:
	Square(std::string name_, int sideA_)
		:Rectangle(name_, sideA_, sideA_) {}
};
class Rhomb :public Parallelogram
{
public:
	Rhomb(std::string name_, int sideA_, int angleA_, int angleB_)
		:Parallelogram(name_, sideA_, sideA_, angleA_, angleB_) {}
};

void print_info(Figure* figure) {
	figure->print_info();
}


int main()
{
	Triangle triangle("Triangle", 10, 20, 30, 40, 50, 90);
	Right_triangle right_triangle("Right-Triangle", 20, 30, 40, 50, 40);
	Isosceles_triangle isosceles_triangle("Isosceles Triangle", 30, 40, 45, 45);
	Equilateral_triangle equilateral_triangle("Equilateral Triangle", 30);
	Rectangle rectangle("Rectangle", 40, 20);
	Square square("Square", 30);
	Rhomb rhomb("Rhomb", 20, 45, 135);

	print_info(&triangle);
	print_info(&right_triangle);
	print_info(&isosceles_triangle);
	print_info(&equilateral_triangle);
	print_info(&rectangle);
	print_info(&square);
	print_info(&rhomb);
}