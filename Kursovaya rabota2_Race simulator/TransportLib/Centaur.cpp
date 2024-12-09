#include "Centaur.h"


Centaur::Centaur() : Ground_transport("Кентавр", 15, 8, 2) {}

double Centaur::time_of_distance(double distance) const 
{
    double time_to_move = distance / speed_; // Общее время движения
    int total_of_stops = (int)(time_to_move / time_before_rest_); // Количество остановок

    // Проверяем остаток времени
    double remaining_time = std::fmod(time_to_move, time_before_rest_);

    // Если остатка нет, последняя остановка — это финиш
    if (remaining_time == 0) 
    {
        total_of_stops--;
    }

    // Общее время отдыха
    double rest_time = total_of_stops * time_to_rest_; // Все остановки — по 2 часа

    return time_to_move + rest_time;
}
