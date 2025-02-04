#pragma once
#include <iostream>
#include <vector>

class Counter
{
private:
    int sum = 0;     // переменная для суммы чисел
    int count = 0;   // переменная для количества чисел делящихся на три

public:
    void operator()(int number) //перегрузка оператора ()
    {
        if (number % 3 == 0) // Если число делится на 3 без остатка
        {
            sum += number;
            count++;
        }
    }
    int get_sum() const { return sum; }
    int get_count() const { return count; }
};

// шаблон вывода вектора в консоль
template<typename T>
void printVector(const std::vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << (i + 1 < vector.size() ? ", " : "\n");
    }
}
