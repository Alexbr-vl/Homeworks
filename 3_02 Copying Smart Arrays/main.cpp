#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include <algorithm>

class smart_array 
{
private:
    int* data;         // Указатель на массив
    int capacity;      // Вместимость массива
    int size;          // Текущее количество элементов

public:
    // Конструктор по умолчанию
    smart_array() : data(nullptr), capacity(0), size(0) {}

    // Конструктор копирования
    smart_array(const smart_array& other)
        : data(nullptr), capacity(other.capacity), size(other.size) 
    {
        if (capacity > 0) 
        {
            data = new int[capacity];
            std::copy(other.data, other.data + size, data); // Безопасное копирование
        }
    }
    // Метод для создания массива
    void create_array(int new_capacity)
    {
        if (new_capacity <= 0)
        {
            throw std::invalid_argument("Ошибка: Размер массива должен быть больше 0");
        }
        delete[] data; // Освобождаем предыдущую память
        data = new int[new_capacity] {}; // Инициализация массива
        capacity = new_capacity;
        size = 0;
    }

    // Добавление элемента
    void add_element(int value)
    {
        if (!data)
        {
            throw std::logic_error("Ошибка: массив не создан. Сначала вызовите create_array.");
        }
        if (size >= capacity)
        {
            throw std::overflow_error("---===Ошибка: Превышен размер массива===---");
        }
        data[size++] = value;
    }

    // Получение элемента по индексу
    int get_element(int index) const
    {
        if (!data)
        {
            throw std::logic_error("Ошибка: массив не создан. Сначала вызовите create_array.");
        }
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("---===Ошибка: Индекс выходит за границы массива===---");
        }
        return data[index];
    }

    // Деструктор
    ~smart_array()
    {
        delete[] data;
    }
   
    // Оператор присваивания
    smart_array& operator=(const smart_array& other) 
    {
        if (this == &other) return *this;

        // Освобождаем текущую память
        delete[] data;

        // Копируем параметры
        capacity = other.capacity;
        size = other.size;

        if (capacity > 0) 
        {
            data = new int[capacity];
            std::copy(other.data, other.data + size, data); // Безопасное копирование
        }
        else 
        {
            data = nullptr;
        }
        return *this;
    }

    // Получение текущего размера массива
    int get_size() const 
    {
        return size;
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try 
    {
        smart_array arr;

        // Создаём массив с вместимостью 5
        arr.create_array(5);

        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array;

        // Создаём массив с вместимостью 4
        new_array.create_array(4);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array; // Копируем объект 2 в объект 1

        std::cout << "Элементы массива arr после присвоения: " << std::endl;
        for (int i = 0; i < arr.get_size(); i++) 
        {
            std::cout << arr.get_element(i) << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& ex) 
    {
        std::cerr << ex.what() << std::endl;
    }
}
