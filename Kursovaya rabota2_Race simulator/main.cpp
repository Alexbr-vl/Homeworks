#include <iostream>
#include "Transport.h"
#include "Ground_transport.h"
#include "Camel.h"
#include "Fast_camel.h"
#include "Centaur.h"
#include "All_terrain_boots.h"
#include "Air_transport.h"
#include "Magic_carpet.h"
#include "Eagle.h"
#include "Broomstick.h"
#include "Windows.h"



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Camel camel;
    Fast_camel fast_camel;
    Centaur centaur;
    All_terrain_boots boots;

    Magic_carpet carpet;
    Eagle eagle;
    Broomstick broom;

    double distance = 4500;

    std::cout << camel.get_name() << " преодолеет дистанцию " << distance << " за " << camel.time_of_distance(distance) << " часов" << std::endl;
    std::cout << fast_camel.get_name() << " преодолеет дистанцию " << distance << " за " << fast_camel.time_of_distance(distance) << " часов" << std::endl;
    std::cout << centaur.get_name() << " преодолеет дистанцию " << distance << " за " << centaur.time_of_distance(distance) << " часов" << std::endl;
    std::cout << boots.get_name() << " преодолеет дистанцию " << distance << " за " << boots.time_of_distance(distance) << " часов" << std::endl;

    std::cout << carpet.get_name() << " преодолеет дистанцию " << distance << " за " << carpet.time_of_distance(distance) << " часов" << std::endl;
    std::cout << eagle.get_name() << " преодолеет дистанцию " << distance << " за " << eagle.time_of_distance(distance) << " часов" << std::endl;
    std::cout << broom.get_name() << " преодолеет дистанцию " << distance << " за " << broom.time_of_distance(distance) << " часов" << std::endl;
}