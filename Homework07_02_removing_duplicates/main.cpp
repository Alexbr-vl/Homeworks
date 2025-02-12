#include <iostream>
#include <set>

int main() 
{
    int x;
    std::cout << "IN: " << std::endl;
    std::cout << "enter the number of items: ";  
    std::cin >> x; // Считываем количество элементов

    std::set<int> uniq_numbers; // Используем set для хранения уникальных чисел
    for (int i = 0; i < x; ++i) 
    {
        int num;
        
        std::cout << "enter the (" << i+1 << ") element: ";
        std::cin >> num;
        uniq_numbers.insert(num); // Добавляем числа в set (дубликаты игнорируются)
    }

    // Выводим элементы set в обратном порядке
    std::cout << "\nOUT: " << std::endl;
    for (auto it = uniq_numbers.rbegin(); it != uniq_numbers.rend(); ++it) 
    {
        std::cout << *it << std::endl;
    }
}