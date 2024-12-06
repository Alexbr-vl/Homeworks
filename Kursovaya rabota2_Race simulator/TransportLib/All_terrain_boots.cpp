#include "All_terrain_boots.h"


All_terrain_boots::All_terrain_boots() : Ground_transport("Ботинки-вездеходы", 6, 60, 10) {}

double All_terrain_boots::time_of_distance(double distance) const {
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
        rest_time += 10; // Первая остановка — 10 часов
    }
    if (total_of_stops > 1) {
        rest_time += (total_of_stops - 1) * 5; // Остальные остановки — по 5 часов
    }

    return time_to_move + rest_time;
}
