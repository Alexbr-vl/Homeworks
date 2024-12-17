#include <iostream>


// Время(O(2 ^ n)) : Время работы программы растет экспоненциально, потому что для каждого вызова fibonacci(n) создаются 
// два новых вызова(для fibonacci(n - 1) и fibonacci(n - 2)).Это приводит к экспоненциальному числу вычислений, что даёт
// сложность O(2 ^ n).

// Память(O(n)) : Память растет линейно в зависимости от глубины рекурсии.Максимальная глубина 
// рекурсии для числа n будет O(n), так как каждый новый рекурсивный вызов увеличивает глубину на 1.


    int fibonacci(int n) 
    {
        if (n <=2) 
        {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
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