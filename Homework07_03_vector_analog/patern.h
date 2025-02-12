﻿#include <stdexcept> 

template <typename T>
class MyVector 
{
private:
    T* data;          // Указатель на массив элементов
    size_t vec_size;   // Текущее количество элементов
    size_t vec_capacity; // Текущая вместимость

    void resize() 
    {
        if (vec_capacity == 0) 
        {
            vec_capacity = 1;
            data = new T[vec_capacity];
        }
        else 
        {
            vec_capacity *= 2;
            T* new_data = new T[vec_capacity];
            for (size_t i = 0; i < vec_size; ++i) 
            {
                new_data[i] = data[i]; // Копируем элементы
            }
            delete[] data; // Освобождаем старую память
            data = new_data;
        }
    }

public:
    // Конструктор
    MyVector() : data(nullptr), vec_size(0), vec_capacity(0) {}

    // Деструктор
    ~MyVector() 
    {
        delete[] data;
    }

    // Доступ к элементу по индексу
    T& at(size_t index) 
    {
        if (index >= vec_size) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Добавление элемента в конец
    void push_back(T value) 
    {
        if (vec_size >= vec_capacity) 
        {
            resize(); // Увеличиваем вместимость, если нужно
        }
        data[vec_size] = value;
        vec_size++;
    }

    // Текущее количество элементов
    size_t size() const 
    {
        return vec_size;
    }

    // Текущая вместимость
    size_t capacity() const 
    {
        return vec_capacity;
    }
};
