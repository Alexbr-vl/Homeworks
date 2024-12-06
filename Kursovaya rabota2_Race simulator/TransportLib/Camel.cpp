#include "Camel.h"

Camel::Camel() : Ground_transport("Верблюд", 10, 30, 5) {}

double Camel::time_of_distance(double distance) const {
    double time_to_move = distance / speed_; // Общее время движения
    int total_of_stops = (int)(time_to_move / time_before_rest_); // Количество остановок

    // Проверяем, остаётся ли часть времени после последнего полного цикла
    double remaining_time = std::fmod(time_to_move, time_before_rest_);

    // Если остатка нет, последняя остановка — это финиш, уменьшаем количество остановок
    if (remaining_time == 0) {
        total_of_stops--;
    }

    // Время на отдых
    double rest_time = 0;
    if (total_of_stops > 0) {
        rest_time += time_to_rest_; // Первая остановка — 5 часов
    }
    if (total_of_stops > 1) {
        rest_time += (total_of_stops - 1) * 8; // Остальные — по 8 часов
    }

    return time_to_move + rest_time;
}
