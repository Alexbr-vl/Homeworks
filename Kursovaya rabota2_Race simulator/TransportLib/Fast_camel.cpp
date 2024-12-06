#include"Fast_camel.h"

Fast_camel::Fast_camel() : Ground_transport("Верблюд-скороход", 40, 10, 5) {}

double Fast_camel::time_of_distance(double distance) const {
    double time_to_move = distance / speed_; // Общее время движения
    int total_of_stops = (int)(time_to_move / time_before_rest_); // Количество остановок

    // Проверяем остаток времени
    double remaining_time = std::fmod(time_to_move, time_before_rest_);

    // Если остатка нет, последняя остановка — это финиш
    if (remaining_time == 0) {
        total_of_stops--;
    }

    // Время на отдых
    double rest_time = 0;
    if (total_of_stops > 0) {
        rest_time += 5; // Первая остановка — 5 часов
    }
    if (total_of_stops > 1) {
        rest_time += 6.5; // Вторая остановка — 6.5 часов
    }
    if (total_of_stops > 2) {
        rest_time += (total_of_stops - 2) * 8; // Остальные остановки — по 8 часов
    }

    return time_to_move + rest_time;
}
