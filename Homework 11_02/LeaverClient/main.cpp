#include <iostream>
#include "Leaver.h"

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    Leaver leaver;
    std::cout << leaver.leave(name) << std::endl;
}
