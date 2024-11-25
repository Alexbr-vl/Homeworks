#include <iostream>
#include<Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	
	// Нахождение наибольшего общего делителя
	int gcd(int numerator_, int denominator_) const
	{
		while (denominator_ != 0)
		{
			int temp = denominator_;
			denominator_ = numerator_ % denominator_;
			numerator_ = temp;
		}
		return numerator_;
	}

public:
	Fraction(int numerator = 1, int denominator = 1) : numerator_(numerator), denominator_(denominator) { normalize(); }
	
	void normalize()// Сокращаем дробь и приводим к правильному виду
	{
		int divisor = gcd(numerator_, denominator_);
		numerator_ /= divisor;
		denominator_ /= divisor;
		
		if (denominator_ < 0)
		{
			numerator_ = -numerator_;
			denominator_ = -denominator_;
		}
	}
	
	void print() const //функция вывода дробей
	{
		std::cout << numerator_ << "/" << denominator_;
	}
	void input(int fractionNumber) // функция ввода дробей
	{
		std::cout << "Введите числитель дроби " << fractionNumber << ": "; std::cin >> numerator_;
		std::cout << "Введите знаменатель дроби " << fractionNumber << ": "; std::cin >> denominator_;
	}
	void printOperation(const Fraction& f, const std::string& operation, const Fraction& result) const // функция вывода результатов операций +,-,*,/
	{
		this->print();
		std::cout << " " << operation << " ";
		f.print();
		std::cout << " = ";
		result.print();
		std::cout << '\n';
	}

	// операции +,-,*,/
	Fraction operator+(const Fraction f) const 
	{ 
		return Fraction (numerator_ * f.denominator_ + f.numerator_ * denominator_,
						 denominator_ * f.denominator_);
	}
	Fraction operator-(const Fraction f) const
	{
		return Fraction(numerator_ * f.denominator_ - f.numerator_ * denominator_,
						denominator_ * f.denominator_);
	}
	Fraction operator*(const Fraction f) const
	{
		return Fraction(numerator_ * f.numerator_,
						denominator_ * f.denominator_);
	}
	Fraction operator/(const Fraction f) const
	{
		return Fraction(numerator_ * f.denominator_,
						denominator_ * f.numerator_);
	}
	
	Fraction operator-() const // Унарный минус
	{
		return Fraction(-numerator_, denominator_);
	}
	Fraction& operator++() // Префиксный инкремент
	{
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator++(int) // Постфиксный инкремент
	{
		Fraction temp = *this;
		numerator_ += denominator_;
		return temp;
	}
	Fraction& operator--() // Префиксный декремент
	{
		numerator_ -= denominator_;
		return *this;
	}
	Fraction operator--(int) // Постфиксный декремент
	{
		Fraction temp = *this;
		numerator_ -= denominator_;
		return temp;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Fraction f1, f2;
	f1.input(1); //вводим числитель и знаменатель первой дроби
	f2.input(2); //вводим числитель и знаменатель второй дроби

	std::cout << "\nРезультаты вычислений: \n";
	
	f1.printOperation(f2, "+", f1 + f2);
	f1.printOperation(f2, "-", f1 - f2);
	f1.printOperation(f2, "*", f1 * f2);
	f1.printOperation(f2, "/", f1 / f2);
	
	std::cout << '\n' << "\nУнарный минус: ";
	(-f1).print();
	std::cout << '\n' << '\n';

	std::cout << "\nДемонстрация префиксного и постфиксного инкремента/декремента:\n";

	// Префиксный инкремент
	std::cout << "++";
	f1.print();
	std::cout << " * ";
	f2.print();
	std::cout << " = ";
	Fraction result1 = (++f1) * f2;
	result1.print();
	std::cout << '\n';
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << '\n' << '\n';

	// Постфиксный декремент
	f1.print();
	std::cout << "-- * ";
	f2.print();
	std::cout << " = ";
	Fraction result2 = (f1--) * f2;
	result2.print();
	std::cout << '\n';
	std::cout << "Значение дроби 1 = ";
	f1.print();
	std::cout << '\n';
}