#include <iostream>
#include <stdexcept>
#include <Windows.h>

class smart_array 
{
private:
    int* data;         // Указатель на массив
    int capacity;      // Вместимость массива
    int size;          // Текущее количество элементов

public:
    // Конструктор
    smart_array() : data(nullptr), capacity(0), size(0) {}

    // Метод для создания массива
    void create_array(int new_capacity) 
    {
        if (new_capacity <= 0) 
        {
            throw std::invalid_argument("Ошибка: Размер массива должен быть больше 0");
        }
        if (data) delete[] data; // Защита от утечек памяти
        data = new int[new_capacity]{};
        capacity = new_capacity;
        size = 0;
    }

    // Деструктор
    ~smart_array() 
    {
        delete[] data;  // Освобождаем выделенную память
    }

    // Добавление элемента
    void add_element(int value) 
    {
        if (size >= capacity) 
        {
            throw std::overflow_error("---===Ошибка: Превышен размер массива===---");
        }
        data[size++] = value;
    }

    // Получение элемента по индексу
    int get_element(int index) const 
    {
        if (index < 0 || index >= size) 
        {
            throw std::out_of_range("---===Ошибка: Индекс выходит за границы массива===---");
        }
        return data[index];
    }
    //не требуются в этой задаче
    //int get_size() const { return size; }
    //int get_capacity() const { return capacity; }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try {
        smart_array arr;
        arr.create_array(5);

        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        while (true) 
        {
            std::cout << "Введите индекс для получения элемента (-1 для выхода): ";
            int index;
            std::cin >> index;

            if (index == -1) 
            {
                std::cout << "Выход из программы." << std::endl;
                break;
            }

            try 
            {
                std::cout << "Элемент с индексом " << index << ": " << arr.get_element(index) << std::endl;
            }
            catch (const std::exception& ex) 
            {
                std::cerr << ex.what() << std::endl;
            }
        }
    }
    catch (const std::exception& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }
}
