#include <iostream>
#include <Windows.h>

// Вывод на консоль
void print_array(const int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Соединение двух подмассивов
void merge(int* arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Временные массивы для левой и правой части
    int* temp = new int[right - left + 1];

    int i = left, j = mid + 1, k = 0;

    // Слияние подмассивов в temp
    while (i <= mid && j <= right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }

    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }

    // Копируем данные из temp обратно в исходный массив
    for (k = 0; k < n1 + n2; k++) 
    {
        arr[left + k] = temp[k];
    }
    delete[] temp;
}

// Рекурсивная функция сортировки слиянием
void merge_sort_recursive(int* arr, int left, int right) 
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Основная функция для сортировки слиянием
void merge_sort(int* arr, int size) 
{
    merge_sort_recursive(arr, 0, size - 1);
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "Исходный массив: ";
    print_array(arr1, size1);
    merge_sort(arr1, size1);
    std::cout << "Отсортированный массив:  ";
    print_array(arr1, size1);

    std::cout << "\nИсходный массив: ";
    print_array(arr2, size2);
    merge_sort(arr2, size2);
    std::cout << "Отсортированный массив:  ";
    print_array(arr2, size2);

    std::cout << "\nИсходный массив: ";
    print_array(arr3, size3);
    merge_sort(arr3, size3);
    std::cout << "Отсортированный массив:  ";
    print_array(arr3, size3);
}
