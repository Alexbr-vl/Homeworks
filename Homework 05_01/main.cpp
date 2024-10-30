#include<iostream>
#include<string>



class Figure
{
public:
	Figure() : sides_count(0), name("Unknown figure") {}
	Figure(int sides_count, std::string name) :sides_count(sides_count), name(name) {}
	
	int get_sides_count()
	{
		return sides_count;
	}
	std::string get_name()
	{
		return name;
	}
	void print_info() {
		std::cout << get_name() << " have " << get_sides_count() << " sides." << std::endl;
	}
protected:
	int sides_count;
	std::string name;
};

class Triangle:public Figure
{
public:
	Triangle() :Figure(3, "Triangle") {}
};

class Quadrangle :public Figure
{
public:
	Quadrangle() : Figure(4, "Quadrangle") {}
};



int main()
{
	Figure unknown;
	Triangle triangle;
	Quadrangle quadrangle;

	unknown.print_info();
	triangle.print_info();
	quadrangle.print_info();
}