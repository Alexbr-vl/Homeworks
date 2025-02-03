#include "pattern.h"  // Подключаем заголовочный файл с шаблонными функциями

int main() {
    int num = 4;
    std::cout << "[IN]: " << num << std::endl;
    std::cout << "[OUT]: " << square(num) << std::endl;

    std::vector<int> my_vector = { -1, 4, 8 };
    std::cout << "[IN]: ";
    printVector(my_vector);

    std::vector<int> result_vector = square(my_vector);
    std::cout << "[OUT]: ";
    printVector(result_vector);
}