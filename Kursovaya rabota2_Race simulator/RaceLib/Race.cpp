#include "Race.h"
#include <iomanip>

// Конструктор
Race::Race(double distance)
    : distance_(distance), participant_count_(0) 
{
    for (int i = 0; i < max_participants; ++i)
    {
        participants_[i] = nullptr; // Инициализируем массив
    }
}

// Добавление участника
void Race::add_participant(Transport* transport) 
{
    // Проверяем на переполнение
    if (participant_count_ >= max_participants) 
    {
        std::cout << "Статус регистрации: ---===Ошибка: достигнуто максимальное количество участников!===---\n";
        delete transport;
        return;
    }

    // Проверяем на дублирование
    for (int i = 0; i < participant_count_; ++i) 
    {
        if (participants_[i]->get_name() == transport->get_name()) 
        {
            std::cout << "Статус регистрации: ---===Ошибка: " << transport->get_name() << " уже зарегистрирован!!!===---\n";
            delete transport;
            return;
        }
    }

    // Добавляем участника
    participants_[participant_count_++] = transport;
    std::cout << "Статус регистрации: " << transport->get_name() << " успешно зарегистрирован.\n";
}

int Race::get_participant_count() const { return participant_count_; }

Transport* Race::get_participant(int index) const 
{
    if (index < 0 || index >= participant_count_) 
    {
        return nullptr; // Возвращаем nullptr, если индекс некорректный
    }
    return participants_[index];
}

// Проведение гонки (сортировка пузырьком)
void Race::run_race() 
{
    for (int i = 0; i < participant_count_ - 1; ++i) 
    {
        for (int j = 0; j < participant_count_ - i - 1; ++j) 
        {
            if (participants_[j]->time_of_distance(distance_) > participants_[j + 1]->time_of_distance(distance_)) 
            {
                // Меняем местами участников
                Transport* temp = participants_[j];
                participants_[j] = participants_[j + 1];
                participants_[j + 1] = temp;
            }
        }
    }
}

// Вывод результатов
void Race::print_results() const 
{
    std::cout << "\nРезультаты гонки:\n";
    std::cout << std::left << std::setw(20) << "Участник"
        << std::setw(15) << "Время (ч)" << "\n";
    std::cout << std::string(35, '-') << "\n";

    for (int i = 0; i < participant_count_; ++i) 
    {
        std::cout << std::left << std::setw(20) << participants_[i]->get_name()
            << std::setw(15) << participants_[i]->time_of_distance(distance_)
            << "\n";
    }
}

// Деструктор
Race::~Race() 
{
    for (int i = 0; i < participant_count_; ++i) 
    {
        delete participants_[i]; // Удаляем каждого участника
    }
}
