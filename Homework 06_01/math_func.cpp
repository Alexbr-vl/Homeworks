#include"math_func.h"

int addition(int a, int b)
{
	return a + b;
}
int subtraction(int a, int b)
{
	return a - b;
}
int multiplication(int a, int b)
{
	return a * b;
}
double division(double a, double b)
{
	return a / b;
}
int exponentiation(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}
