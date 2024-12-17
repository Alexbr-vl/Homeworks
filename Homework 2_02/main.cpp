#include <iostream>

int fibonacci(int n)
{

    if (n <= 2)
    {
        return 1;
    }

    // ƒинамический массив дл€ хранени€ чисел + инициализаци€ первых трех чисел
    int* memo = new int[n + 1];
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    // «аполн€ем массив числами
    for (int i = 3; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    int result = memo[n];

    // ќсвобождаем пам€ть
    delete[] memo;

    return result;
}

int main()
{
    int n;
    while (true)
    {
        std::cout << "Enter a number: ";
        std::cin >> n;

        std::cout << "The Fibonacci number for n =" << n << ": " << fibonacci(n) << std::endl;
    }
}
