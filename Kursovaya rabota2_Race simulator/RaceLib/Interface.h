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
    Race* create_race();        // Создать гонку
    void register_participants(Race* race); // Зарегистрировать участников
};