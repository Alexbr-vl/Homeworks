#pragma once
#include "Ground_race.h"
#include "Air_race.h"
#include "Mix_race.h"

class Interface
{
public:
    
    void run(); // Запуск интерфейса
  
private:
    void menu();           // Отобразить главное меню
    Race* create_race(int choice);        // Создать гонку
    void register_participants(Race* race); // Зарегистрировать участников
    int get_valid_int(const std::string& prompt, int min, int max);
    double get_valid_positive_double(const std::string& prompt);
};