#include <iostream>
#include "patern.h"

int main() 
{
    // Пример использования
    MyVector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;      
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " "; 
    }
    std::cout << std::endl;

    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(9);

    std::cout << "\nSize: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "\nUsing the copy constructor and assignment operator: \n";
    // Использование конструктора копирования
    MyVector<int> vec2 = vec;

    // Использование оператора присваивания
    MyVector<int> vec3;
    vec3 = vec;

    std::cout << "vec1: ";
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) 
    {
        std::cout << vec2.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "vec3: ";
    for (size_t i = 0; i < vec3.size(); ++i) 
    {
        std::cout << vec3.at(i) << " ";
    }
    std::cout << std::endl;
}