#include "MyClass.h"

int main()
{
	Counter counter;
	int figure;
	char symbol = '0';

	while (symbol != 'y' && symbol != 'n')
	{
		std::cout << "Do you want to specify the initial value of the counter? (y/n?)"; std::cin >> symbol;
	}

	if (symbol == 'y')
	{
		std::cout << "Enter the initial value of the counter: "; std::cin >> figure;
		counter.set_initial_value(figure);
	}

	while (true)
	{
		std::cout << "Enter the command ('+', '-', '=' or 'x'): "; std::cin >> symbol;

		switch (symbol)
		{
		case '+': counter.plus(); break;
		case '-': counter.minus(); break;
		case '=': counter.print(); break;
		case 'x': counter.quit(); break;
		default:
		{
			std::cout << "\nInvalid command. Please enter '+', '-', '=' or 'x'." << std::endl;
			break;
		}
		}
	}
}