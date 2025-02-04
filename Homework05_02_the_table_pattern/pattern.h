#pragma once
#include <iostream>
#include <vector>

// Шаблон класса
template <typename T>
class Table 
{
public:
    // Конструктор, создающий таблицу с заданным количеством строк и столбцов
    Table(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)) {}

    // Неконстантный оператор [] для изменяемых таблиц
    std::vector<T>& operator[](size_t index) 
    {
        return data[index];
    }

    // Константный оператор [] для неизменяемых таблиц
    const std::vector<T>& operator[](size_t index) const 
    {
        return data[index];
    }

    void Size(size_t& rows, size_t& cols) const
    {
        rows = data.size();

        if (data.empty()) 
        {
            cols = 0;
        }
        else 
        {
            cols = data[0].size();
        }
    }

private:
    std::vector<std::vector<T>> data; // Двумерный массив, список списков, она же таблица
};
