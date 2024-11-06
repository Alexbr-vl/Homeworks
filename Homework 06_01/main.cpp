#include<iostream>
#include"math_func.h"

int main()
{
	int a, b, choice;
	while(true)
	{
		std::cout << "Enter the first number: "; std::cin >> a;
		std::cout << "Enter the second number: "; std::cin >> b;
		std::cout << "Select an operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation): "; std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << a << " + " << b << " = " << addition(a, b) << "\n" << std::endl; break;
		case 2:
			std::cout << a << " - " << b << " = " << subtraction(a, b) << "\n" << std::endl; break;
		case 3:
			std::cout << a << " * " << b << " = " << multiplication(a, b) << "\n" << std::endl; break;
		case 4:
			std::cout << a << " / " << b << " = " << division(a, b) << "\n" << std::endl; break;
		case 5:
			std::cout << a << " to the " << b << "th degree" << " = " << exponentiation(a, b) << "\n" << std::endl; break;
		default:
			std::cout << "Make the right choice\n" << std::endl;
		}
	}
}