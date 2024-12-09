//подключаем все необходимые классы и библиотеки
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
#include "Interface.h"
#include "Windows.h"



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Interface iface; //создаем объект класса Interface
    iface.run(); //запускаем метод run, класса Interface
}