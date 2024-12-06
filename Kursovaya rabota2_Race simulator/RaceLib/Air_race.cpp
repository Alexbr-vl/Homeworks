#include "Air_race.h"


void Air_race::add_participant(Transport* transport)
{
    // Проверяем, является ли ТС воздушным
    if (transport->is_air_transport())
    {
        Race::add_participant(transport);
    }
    else
    {
        std::cout << "Ошибка: можно регистрировать только воздушные транспортные средства!\n";
    }
}
