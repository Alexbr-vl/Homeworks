#include <iostream>

class Calculator
{
private:
	double num1;
	double num2;

public:
	//конструктор
	Calculator() : num1(1), num2(1) {}

	bool set_num1(double value) //сеттер num1
	{
		if (value != 0) {
			num1 = value;
			return true;
		}
		else {
			return false;
		}
	}
	bool set_num2(double value) //сеттер num2
	{
		if (value != 0) {
			num2 = value;
			return true;
		}
		else {
			return false;
		}
	}
	
	// методы для арифметических действий
	double add ()			const { return (num1 + num2); }
	double multiply ()		const { return (num1 * num2); }
	double subtract_1_2 ()  const { return (num1 - num2); }
	double subtract_2_1 ()  const { return (num2 - num1); }
	double divide_1_2 ()	const { return (num1 / num2); }
	double divide_2_1 ()	const { return (num2 / num1); }
};

//функция для проверки на ноль
double input_number(const std::string& text)
{
	double value;
	while (true) {
		std::cout << text;
		std::cin >> value;
		if (value != 0) {
			return value;
		}
		std::cout << "**** Mistake!!! Enter a number other than zero****" << std::endl;
	}
}

int main()
{
	Calculator newCalculator;
	
	while (true)
	{
		double num1 = input_number("Enter num1: ");
		double num2 = input_number("Enter num2: ");
		newCalculator.set_num1(num1);
		newCalculator.set_num2(num2);

		std::cout << "num1 + num2 = " << newCalculator.add() << std::endl;
		std::cout << "num1 * num2 = " << newCalculator.multiply() << std::endl;
		std::cout << "num1 - num2 = " << newCalculator.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << newCalculator.subtract_2_1() << std::endl;
		std::cout << "num1 / num2 = " << newCalculator.divide_1_2() << std::endl;
		std::cout << "num2 + num1 = " << newCalculator.divide_2_1() << std::endl;
		std::cout << std::endl;
	}
}