#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

int main()
{
    std::string text;
    std::cout << "[IN]: ";
    std::getline(std::cin, text);  // Считываем строку целиком

    std::unordered_map<char, int> freq;  // Хэш-таблица для подсчёта частоты

    // Подсчёт частоты символов (игнорируем пробелы)
    for (char c : text)
    {
        if (c != ' ')
        {
            freq[c]++;
        }
    }

    // multimap автоматически сортирует по убыванию частоты
    std::multimap<int, char, std::greater<int>> sorted_freq;

    // Заполняем multimap (меняем местами ключ и значение)
    for (const auto& pair : freq)
    {
        sorted_freq.insert({ pair.second, pair.first });
    }

    std::cout << "[OUT]:\n";
    // Выводим отсортированные символы
    for (const auto& pair : sorted_freq)
    {
        std::cout << pair.second << ": " << pair.first << "\n";
    }
}
