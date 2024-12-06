#include "Race.h"

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
    if (participant_count_ >= max_participants) 
    {
        std::cout << "Ошибка: нельзя добавить больше участников!\n";
        return;
    }
    participants_[participant_count_++] = transport;
}

int Race::get_participant_count() const { return participant_count_; }

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
    for (int i = 0; i < participant_count_; ++i) 
    {
        std::cout << participants_[i]->get_name()
            << ": " << participants_[i]->time_of_distance(distance_) << " часов\n";
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
