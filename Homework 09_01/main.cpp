#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator==(const Fraction& f) const { return numerator_ * f.denominator_ == denominator_ * f.numerator_; }
	bool operator!=(const Fraction& f) const { return !(*this == f); }
	bool operator<(const Fraction& f) const { return numerator_ * f.denominator_ < denominator_ * f.numerator_; }
	bool operator>(const Fraction& f) const { return numerator_ * f.denominator_ > denominator_ * f.numerator_; }
	bool operator<= (const Fraction& f) const { return !(*this > f); }
	bool operator>= (const Fraction & f) const { return !(*this < f); }
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}