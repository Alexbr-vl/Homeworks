#include <iostream>
#include <iomanip>
#include <Windows.h>

void print_pyramid(const int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        int level = 0;
        int temp = i;
        while (temp > 0) 
        {
            temp = (temp - 1) / 2; // Находим родителя
            level++;
        }

        if (i == 0) 
        {
            std::cout << level << " root " << arr[i] << std::endl;
        }
        else 
        {
            int parent_index = (i - 1) / 2;
            if (i == 2 * parent_index + 1) 
            {
                std::cout << level << " left(" << arr[parent_index] << ") " << arr[i] << std::endl;
            }
            else if (i == 2 * parent_index + 2) 
            {
                std::cout << level << " right(" << arr[parent_index] << ") " << arr[i] << std::endl;
            }
        }
    }
}

void print_visual_pyramid(const int* arr, int size) {
    int level = 0;             // Текущий уровень
    int items_in_level = 1;    // Количество элементов на уровне
    int index = 0;             // Индекс текущего элемента массива

    while (index < size) {
        // Вычисляем отступы для текущего уровня
        int spaces = (1 << (4 - level)); // Количество отступов зависит от уровня
        std::cout << std::setw(spaces);

        for (int i = 0; i < items_in_level && index < size; i++, index++) {
            std::cout << arr[index];
            if (i < items_in_level - 1) {
                std::cout << std::setw(spaces * 2) << " "; // Между элементами
            }
        }

        std::cout << std::endl;
        items_in_level *= 2; // На следующем уровне элементов в 2 раза больше
        level++;
    }
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size1; i++) 
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\nПирамида:" << std::endl;
    print_pyramid(arr1, size1);

    std::cout << "\nВизуализация пирамиды:" << std::endl;
    print_visual_pyramid(arr1, size1);

    std::cout << "\nИсходный массив: ";
    for (int i = 0; i < size2; i++) 
    {
        std::cout << arr2[i] << " ";
    }
    std::cout << "\nПирамида:" << std::endl;
    print_pyramid(arr2, size2);

    std::cout << "\nВизуализация пирамиды:" << std::endl;
    print_visual_pyramid(arr2, size2);
}
