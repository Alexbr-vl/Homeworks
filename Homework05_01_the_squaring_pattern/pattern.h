#pragma once
#include <iostream>
#include <vector>

// Общий шаблон возведения в квадрат
template<typename T>
T square(T x) 
{
    return x * x;
}

// перегрузка шаблона для std::vector<T>
template<typename T>
std::vector<T> square(const std::vector<T>& vector) 
{
    std::vector<T> result;
    for (const T& num : vector) //перебираем каждый элемент вектора и ложим его квадрат в новый вектор
    {
        result.push_back(num * num);
    }
    return result;
}

// шаблон вывода вектора в консоль
template<typename T>
void printVector(const std::vector<T>& vector) 
{
    for (size_t i = 0; i < vector.size(); i++) 
    {
        std::cout << vector[i] << (i + 1 < vector.size() ? ", " : "\n");
    }
}