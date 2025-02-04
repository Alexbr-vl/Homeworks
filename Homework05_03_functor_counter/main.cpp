#include "functor.h"  // Подключаем заголовочный файл с шаблонными функциями

int main() 
{
    Counter counter;
    std::vector<int> numbers{ 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: "; 
    printVector(numbers);
    
    for (int number : numbers) // Вызываем функтор для каждого числа
    {
        counter(number);  
    }

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << counter.get_count() << "\n";
}