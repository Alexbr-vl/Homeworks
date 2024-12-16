#include <iostream>
#include "Windows.h"
using namespace std;

// Функция подсчёта количества элементов с размером массива + точка отсчёта
int ElementsBiggerThanPoint(int arr[], int size, int point) 
{
    int left = 0, right = size; // Границы бинарного поиска
    while (left < right) 
    {
        int mid = left + (right - left) / 2; //определение середины
        
        if (arr[mid] > point) 
        {
            right = mid; // если значение середины больше точки отсчета, то ищем в левой части
        }
        else 
        {
            left = mid + 1; // Ищем в правой части
        }
    }
    // left указывает на первый элемент, который больше точки отсчёта
    return size - left;
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Исходный массив
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]); // Определяем размер массива
    int point;

    // Ввод точки отсчёта
    cout << "Введите точку отсчёта: ";
    cin >> point;

    // Вывод результата
    cout << "Количество элементов в массиве больше, чем " << point << ": " << ElementsBiggerThanPoint(arr, size, point) << endl;
}
