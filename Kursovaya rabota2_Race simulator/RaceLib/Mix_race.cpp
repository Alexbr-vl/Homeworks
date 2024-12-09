#include "Mix_race.h"

void Mix_race::add_participant(Transport* transport) 
{
    // В смешанной гонке разрешены все ТС
    Race::add_participant(transport);
}
