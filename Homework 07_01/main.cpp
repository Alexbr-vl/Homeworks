#include <iostream>
#define MODE 1
int add(int a, int b) {
    return a + b;
}

int main() {
#ifdef MODE
    if (MODE == 0) {
        std::cout << "Work in test mode" << std::endl;
    }
    else if (MODE == 1) {
        std::cout << "Work in combat mode" << std::endl;
        int x, y;
        std::cout << "Enter first num: "; std::cin >> x;
        std::cout << "Enter second num: "; std::cin >> y;
        std::cout << "The result of addition: " << add(x, y) << std::endl;
    }
    else {
        std::cout << "Unknown mode.Completion of work" << std::endl;
    }
#else
    #error "Необходимо определить константу MODE"
#endif
}
