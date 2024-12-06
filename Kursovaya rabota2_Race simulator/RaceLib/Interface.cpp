#include "Interface.h"
#include "Camel.h"
#include "Fast_camel.h"
#include "Centaur.h"
#include "All_terrain_boots.h"
#include "Magic_carpet.h"
#include "Eagle.h"
#include "Broomstick.h"

void Interface::run() 
{
    while (true) 
    {
        menu();
        Race* race = create_race(); // Создаём гонку

        if (!race) 
        {
            std::cout << "Выход из программы.\n";
            break;
        }

        register_participants(race); // Регитрация
        race->run_race();            // Запуск гонки
        race->print_results();       // результаты

        std::cout << "\nЧто вы хотите сделать дальше?\n"
                  << "1. Начать новую гонку\n"
                  << "2. Выйти из программы\n"
                  << "Введите ваш выбор: ";
        int choice;
        std::cin >> choice;

        delete race; // Удаляем объект гонки
        if (choice != 1) 
        {
            std::cout << "Выход из программы.\n";
            break;
        }
    }
}

void Interface::menu() 
{
    std::cout << "Выберите тип гонки:\n"
              << "1. Наземная гонка\n"
              << "2. Воздушная гонка\n"
              << "3. Смешанная гонка\n"
              << "4. Выйти из программы\n"
              << "Введите ваш выбор: ";
}

Race* Interface::create_race() 
{
    int race_type;
    std::cin >> race_type;

    if (race_type == 1) 
    {
        double distance;
        std::cout << "Введите дистанцию для наземной гонки: ";
        std::cin >> distance;
        return new Ground_race(distance);
    }
    else if (race_type == 2) 
    {
        double distance;
        std::cout << "Введите дистанцию для воздушной гонки: ";
        std::cin >> distance;
        return new Air_race(distance);
    }
    else if (race_type == 3) 
    {
        double distance;
        std::cout << "Введите дистанцию для смешанной гонки: ";
        std::cin >> distance;
        return new Mix_race(distance);
    }
    else { return nullptr; } // Выход из программы
}

void Interface::register_participants(Race* race) 
{
    while (true) 
    {
        std::cout << "\nВыберите транспортное средство для регистрации:\n"
                  << "1. Верблюд\n"
                  << "2. Верблюд-скороход\n"
                  << "3. Кентавр\n"
                  << "4. Ботинки-вездеходы\n"
                  << "5. Ковёр-самолёт\n"
                  << "6. Орёл\n"
                  << "7. Метла\n"
                  << "8. Закончить регистрацию\n"
                  << "Введите номер: ";

        int choice;
        std::cin >> choice;

        Transport* transport = nullptr;

        // Создаём экземпляр транспорта
        switch (choice) 
        {
        case 1:
            transport = new Camel();
            break;
        case 2:
            transport = new Fast_camel();
            break;
        case 3:
            transport = new Centaur();
            break;
        case 4:
            transport = new All_terrain_boots();
            break;
        case 5:
            transport = new Magic_carpet();
            break;
        case 6:
            transport = new Eagle();
            break;
        case 7:
            transport = new Broomstick();
            break;
        case 8:
            if (race->get_participant_count() >= 2) { return; } // Минимум 2 участника
            else { std::cout << "Ошибка: для гонки нужно минимум 2 участника!\n"; }
            continue;
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
            continue;
        }

        // Пытаемся добавить участника
        race->add_participant(transport);
    }
}
