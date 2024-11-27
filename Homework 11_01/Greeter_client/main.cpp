#include <iostream>
#include "Greeter.h"

int main()
{
    std::string name;
    std::cout << "Enter your name: "; std::cin >> name;
    
    Greeter greeter;
    std::cout << greeter.greet(name) << std::endl;
}

