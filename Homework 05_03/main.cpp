#include<iostream>
#include<string>


class Figure
{
public:
	Figure() : name("Unknown figure"),  sides_count(0){}
	Figure(std::string name_,int sides_count_ ) :name(name_),sides_count(sides_count_)  {}

	virtual bool is_correct() const 
	{
		return sides_count == 0;
	}
	virtual void print_info()
	{
		std::cout << "\033[4m" << name << "\033[0m" << ":" << std::endl << "number of sides: " << sides_count << std::endl;
		std::cout << (is_correct() ? "Correct" : "Incorrect") << std::endl;
	}

protected:
	int sides_count;
	std::string name;
};

class Triangle :public Figure
{
protected:
	int sideA, sideB, sideC, angleA, angleB, angleC;
public:
	Triangle(std::string name_, int sideA_,int sideB_,int sideC_,int angleA_,int angleB_, int angleC_)
		: Figure (name_, 3), sideA(sideA_),sideB(sideB_),sideC(sideC_),angleA(angleA_),angleB(angleB_),angleC(angleC_){}
	
	virtual bool is_correct() const override
	{
		return sides_count == 3 && (angleA+angleB+angleC==180);
	}
	virtual void print_info() override
	{
		std::cout << std::endl;
		Figure::print_info();
		std::cout << "Sides: " << "a=" << sideA << ", b=" << sideB << ", c=" << sideC << std::endl;
		std::cout << "Angles: " << "A=" << angleA << ", B=" << angleB << ", C=" << angleC << std::endl;
	}
};
class Right_triangle : public Triangle
{
public:
	Right_triangle (std::string name_, int sideA_, int sideB_, int sideC_, int angleB_, int angleC_)
		: Triangle (name_, sideA_, sideB_, sideC_, 90, angleB_, angleC_) {}
	virtual bool is_correct() const override
	{
		return Triangle::is_correct() && angleC == 90;
	}
};
class Isosceles_triangle :public Triangle
{
public:
	Isosceles_triangle (std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
		: Triangle (name_, sideA_, sideB_, sideA_, angleA_,angleB_, angleA_){}
	virtual bool is_correct() const override
	{
		return Triangle::is_correct() && sideA==sideC && angleA==angleC;
	}
};
class Equilateral_triangle :public Triangle
{
public:
	Equilateral_triangle (std::string name_, int sideA_)
		: Triangle(name_, sideA_, sideA_, sideA_, 60, 60, 60) {}
	virtual bool is_correct() const override
	{
		return Triangle::is_correct() && sideA ==sideB==sideC && (angleA == angleB == angleC) == 60;
	}
};
class Quadrangle :public Figure
{
protected:
	int sideA, sideB, sideC, sideD, angleA, angleB, angleC, angleD;
public:
	Quadrangle(std::string name_, int sideA_, int sideB_, int sideC_, int sideD_, int angleA_, int angleB_, int angleC_, int angleD_):
		Figure(name_, 4), sideA(sideA_), sideB(sideB_), sideC(sideC_), sideD(sideD_), angleA(angleA_), angleB(angleB_), angleC(angleC_), angleD(angleD_){}
	
	virtual bool is_correct() const override
	{
		return sides_count == 4 && (angleA + angleB + angleC) == 360;
	}
	
	virtual void print_info() override
	{
		std::cout << std::endl;
		Figure::print_info();
		std::cout << "Sides: " << "a="<< sideA << ", b=" << sideB << ", c=" << sideC << ", d=" << sideD << std::endl;
		std::cout << "Angles: " << "A=" << angleA << ", B=" << angleB << ", C=" << angleC << ", D=" << angleD << std::endl;
	}
};
class  Parallelogram :public Quadrangle
{
public:
	Parallelogram(std::string name_, int sideA_, int sideB_, int angleA_, int angleB_)
		: Quadrangle (name_, sideA_, sideB_, sideA_, sideB_, angleA_, angleB_, angleA_, angleB_){}
	
	virtual bool is_correct() const override
	{
		return Quadrangle::is_correct() && sideA == sideC && sideB == sideD && angleA == angleC && angleB == angleD;
	}
};
class Rectangle :public Parallelogram
{
public:
	Rectangle(std::string name_, int sideA_, int sideB_) 
		: Parallelogram (name_, sideA_, sideB_, 90, 90) {}
	
	virtual bool is_correct() const override
	{
		return Parallelogram::is_correct() && (angleA == angleB == angleC == angleD) == 90;
	}
};
class Rhomb :public Parallelogram
{
public:
	Rhomb(std::string name_, int sideA_, int angleA_, int angleB_)
		:Parallelogram (name_,sideA_,sideA_,angleA_,angleB_){}

	virtual bool is_correct() const override
	{
		return Parallelogram::is_correct() && angleA == angleC && angleB == angleD;
	}
};
class Square :public Rectangle 
{
public:
	Square(std::string name_, int sideA_)
		:Rectangle (name_, sideA_, sideA_) {}
	
	virtual bool is_correct() const override
	{
		return Rectangle::is_correct() && (sideA == sideB == sideC == sideD);
	}
};


int main() 
{
	Figure figure;
	Triangle triangle("Triangle", 10, 20, 30, 50, 60, 70);
	Right_triangle right_triangle("Right-triangle", 10, 20, 30, 50, 60);
	Isosceles_triangle isosceles_triangle("Isosceles_triangle", 10, 20, 50, 60);
	Equilateral_triangle equilateral_triangle("Equilateral_triangle", 30);
	Quadrangle quadrangle("Quadrangle", 10, 20, 30, 40, 50, 60, 70, 80);
	Parallelogram parallelogram("Parallelogram", 20, 30, 30, 40);
	Rectangle rectangle("Rectangle", 10, 20);
	Rhomb rhomb("Rhomb", 30, 30, 40);
	Square square("Square", 20);

	figure.print_info();
	triangle.print_info();
	right_triangle.print_info();
	isosceles_triangle.print_info();
	equilateral_triangle.print_info();
	quadrangle.print_info();
	parallelogram.print_info();
	rectangle.print_info();
	rhomb.print_info();
	square.print_info();
}