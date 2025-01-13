#include <iostream>
#include <string>
#include <Windows.h>


// индекc левого потомка
bool get_left_child(int current_index, int size, int& left_child_index) 
{
    left_child_index = 2 * current_index + 1;
    return left_child_index < size;
}

// индекс правого потомка
bool get_right_child(int current_index, int size, int& right_child_index) 
{
    right_child_index = 2 * current_index + 2;
    return right_child_index < size;
}

// Bндекс родителя
bool get_parent(int current_index, int& parent_index) 
{
    if (current_index == 0) {
        return false; // У корня нет родителя
    }
    parent_index = (current_index - 1) / 2;
    return true;
}

// уровень элемента в пирамиде
int get_level(int index) 
{
    int level = 0;
    while (index > 0) {
        index = (index - 1) / 2;
        level++;
    }
    return level;
}

// вывод текущего элемента
void print_current_element(const int* arr, int index) 
{
    int level = get_level(index);  // Получаем уровень текущего элемента

    if (index == 0) 
    {
        std::cout << "Вы находитесь здесь: Уровень 0 (root) " << arr[index] << std::endl;
    }
    else 
    {
        int parent_index = (index - 1) / 2;
        std::string position = (index == 2 * parent_index + 1) ? "left" : "right";
        std::cout << "Вы находитесь здесь: Уровень " << level << " " << position
            << " (" << arr[parent_index] << ") " << arr[index] << std::endl;
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Начало путешествия
    int current_index = 0;
    std::string command;

    do 
    {
        // Печать текущего элемента
        print_current_element(arr, current_index);

        // Запрос команды
        std::cout << "Введите команду (up, left, right, exit): ";
        std::cin >> command;

        if (command == "up") 
        {
            int parent_index;
            if (get_parent(current_index, parent_index)) 
            {
                current_index = parent_index;
                std::cout << "Ок" << std::endl;
            }
            else 
            {
                std::cout << "Ошибка! Отсутствует родитель." << std::endl;
            }
        }
        else if (command == "left") 
        {
            int left_child_index;
            if (get_left_child(current_index, size, left_child_index)) 
            {
                current_index = left_child_index;
                std::cout << "Ок" << std::endl;
            }
            else 
            {
                std::cout << "Ошибка! Отсутствует левый потомок." << std::endl;
            }
        }
        else if (command == "right") 
        {
            int right_child_index;
            if (get_right_child(current_index, size, right_child_index)) 
            {
                current_index = right_child_index;
                std::cout << "Ок" << std::endl;
            }
            else 
            {
                std::cout << "Ошибка! Отсутствует правый потомок." << std::endl;
            }
        }
        else if (command != "exit") 
        {
            std::cout << "Ошибка! Неизвестная команда." << std::endl;
        }

    } while (command != "exit");

    std::cout << "Вы завершили путешествие по пирамиде." << std::endl;
}
