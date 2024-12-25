#include <iostream>
#include <Windows.h>

// Функция для вывода динамического массива
void print_dynamic_array(int* arr, int logical_size, int actual_size) 
{
    for (int i = 0; i < actual_size; i++) 
    {
        if (i < logical_size) 
        {
            std::cout << arr[i] << " ";
        }
        else 
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int actual_size;
    int logical_size;
    int new_element = 1;

    // Ввод размеров массива
    std::cout << "Введите фактичеcкий размер массива: "; std::cin >> actual_size;

    std::cout << "Введите логический размер массива: "; std::cin >> logical_size;

    if (logical_size > actual_size) 
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 0;
    }

    // Создаём динамического массива
    int* arr = new int[actual_size];

    // Ввод элементов массива
    std::cout << "Заполните " << logical_size << " элементов массива: \n";
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Arr[" << i << "] = "; std::cin >> arr[i];
    }
    
    // Заполняем конец нулями
    for (int i = logical_size; i < actual_size; i++)
    {
        arr[i] = 0;
    }

    // Вывод массива
    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    //цикл пока не введут ноль
    while (new_element !=0)
    {
        std::cout << "Введите элемент для добавления: "; std::cin >> new_element;

        //пока не выходим за пределы фактического массива, просто добавляем новый элемент и увеличиваем счётчик размера логического массива
        if (logical_size < actual_size)
        {
            arr[logical_size++] = new_element;
            print_dynamic_array(arr, logical_size, actual_size);
        }
        //когда факт=лог, создаем новый массив в два раза больше, копируем в него элементы, добавляем новый элемент, а старый массив удаляем
        else
        {
            int new_size = actual_size * 2;
            int* new_arr = new int[new_size];
            for (int i = 0; i < logical_size; i++)
            {
                new_arr[i] = arr[i];
            }
            new_arr[logical_size] = new_element;
            for (int i = logical_size+1; i < new_size; i++)
            {
                new_arr[i] = 0;
            }
            
            delete[] arr; //удаляем старый массив

            //обновляем указатель и размеры
            arr = new_arr;
            actual_size = new_size;
            logical_size++;
            print_dynamic_array(arr, logical_size, actual_size);
        }
    }
    delete[] arr;
}
