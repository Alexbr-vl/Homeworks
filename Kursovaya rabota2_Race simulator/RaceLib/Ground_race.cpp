#include "Ground_race.h"

void Ground_race::add_participant(Transport* transport) 
{
    // Проверяем, является ли ТС наземным
    if (transport->is_ground_transport()) 
    {
        Race::add_participant(transport);
    }
    else 
    {
        std::cout << "---===Ошибка: можно регистрировать только наземные транспортные средства!===---\n";
    }
}
