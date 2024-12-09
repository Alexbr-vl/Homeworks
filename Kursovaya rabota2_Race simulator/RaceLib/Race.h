#pragma once
#include "Transport.h"
#include <iostream>

class Race 
{
protected:
    static const int max_participants = 7; // Максимальное количество участников
    Transport* participants_[max_participants]; // Фиксированный массив указателей
    int participant_count_; // Количество текущих участников
    double distance_; // Дистанция гонки

public:
    Race(double distance);

    // Добавить участника
    virtual void add_participant(Transport* transport);
    
    int get_participant_count() const; //счётчик участников
    Transport* get_participant(int index) const;

    // Провести гонку
    void run_race();

    // Вывести результаты
    void print_results() const;

    // Деструктор для очистки памяти
    ~Race();
};
