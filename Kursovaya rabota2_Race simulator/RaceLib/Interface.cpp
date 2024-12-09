#include "Interface.h"
#include "Camel.h"
#include "Fast_camel.h"
#include "Centaur.h"
#include "All_terrain_boots.h"
#include "Magic_carpet.h"
#include "Eagle.h"
#include "Broomstick.h"
#include <cstdlib> 

int Interface::get_valid_int(const std::string& prompt, int min, int max) //проверка ввода целого цисла в заданном диапазоне
{   
    int value;
    while (true) 
    {
        std::cout << prompt;
        std::cin >> value;

        // Проверяем состояние потока
        if (std::cin.fail() || value < min || value > max) {
            std::cout << "Ошибка: введите число от " << min << " до " << max << ".\n";
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем оставшийся ввод
            return value; // Корректное значение
        }
    }
}

double Interface::get_valid_positive_double(const std::string& prompt) //проверка ввода положительного числа
{
    double value;
    while (true) 
    {
        std::cout << prompt;
        std::cin >> value;
        system("cls");
        // Проверяем состояние потока и значение
        if (std::cin.fail() || value <= 0) 
        {
            std::cout << "Ошибка: введите положительное число.\n";
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
        }
        else 
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем оставшийся ввод
            return value; // Корректное значение
        }
    }
}



void Interface::run() 
{
    while (true) 
    {
        menu(); // Отображаем меню и получаем выбор
        int choice = get_valid_int("Введите ваш выбор: ", 1, 4);

        if (choice == 4) 
        {
            std::cout << "Выход из программы.\n";
            break;
        }

        // Создаём гонку на основе выбора
        Race* race = create_race(choice);

        // Регистрируем участников, запускаем гонку
        register_participants(race);
        race->run_race();
        race->print_results();
        delete race;

        // Перезапуск или завершение
        std::cout << "\nХотите начать новую гонку?\n"
            << "1. Да\n"
            << "2. Нет\n"
            << "Введите ваш выбор: ";
        int restart_choice = get_valid_int("", 1, 2);
        if (restart_choice == 2) 
        {
            std::cout << "Выход из программы.\n";
            break;
        }
        system("cls");
    }
}

void Interface::menu() // стартовое меню
{
    std::cout << "Выберите тип гонки:\n"
        << "1. Наземная гонка\n"
        << "2. Воздушная гонка\n"
        << "3. Смешанная гонка\n"
        << "4. Выйти из программы\n";
}

Race* Interface::create_race(int choice)  //создаем гонку
{
    double distance = get_valid_positive_double("Введите дистанцию для гонки: ");

    switch (choice) 
    {
        case 1:return new Ground_race(distance);
        case 2:return new Air_race(distance);
        case 3:return new Mix_race(distance);
        default:return nullptr;
    }
}

void Interface::register_participants(Race* race) //регистрируем участников
{
    while (true) 
    {
        int choice = get_valid_int("\nВыберите транспортное средство для регистрации:\n"
            "1. Верблюд\n"
            "2. Верблюд-скороход\n"
            "3. Кентавр\n"
            "4. Ботинки-вездеходы\n"
            "5. Ковёр-самолёт\n"
            "6. Орёл\n"
            "7. Метла\n"
            "8. Закончить регистрацию\n"
            "Введите номер: ",
            1, 8);

        if (choice == 8) 
        {
            if (race->get_participant_count() >= 2) 
            {
                return;
            }
            else 
            {
                std::cout << "---===Ошибка: для гонки нужно минимум 2 участника!===---\n";
            }
            continue;
        }

        Transport* transport = nullptr;

        switch (choice) // Создаём экземпляр транспорта
        {
            case 1: transport = new Camel(); break;
            case 2: transport = new Fast_camel(); break;
            case 3: transport = new Centaur(); break;
            case 4: transport = new All_terrain_boots(); break;
            case 5: transport = new Magic_carpet(); break;
            case 6: transport = new Eagle(); break;
            case 7: transport = new Broomstick(); break;
            default: break;
        }
        system("cls");
        race->add_participant(transport);// Добавляем участника
        

        // Выводим список зарегистрированных участников
        std::cout << "\nСписок зарегистрированных участников:\n";
        for (int i = 0; i < race->get_participant_count(); ++i)
        {
            Transport* participant = race->get_participant(i);
            if (participant)
            {
                std::cout << i + 1 << ". " << participant->get_name() << "\n";
            }
        }
    }
}
