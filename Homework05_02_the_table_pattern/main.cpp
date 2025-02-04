#include "pattern.h"  // Подключаем заголовочный файл с шаблонными функциями

int main() 
{
    Table<int> table(2, 3); // Создаём таблицу 2x3
    table[0][0] = 4;        // Записываем значение
    std::cout << table[0][0] << std::endl; // Выводим значение table[0][0] в консоль

    size_t rows, cols;
    table.Size(rows, cols);
    std::cout << "Size: " << rows << "x" << cols << std::endl; // Вывод размера таблицы
}