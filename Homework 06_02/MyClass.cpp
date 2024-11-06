#include "MyClass.h"

Counter::Counter() : initial_value(1) {}
int Counter::plus() { return initial_value++; }
int Counter::minus() { return initial_value--; }
void Counter::print() { std::cout << "------> " << initial_value << " <------" << std::endl; }
void Counter::quit() { std::cout << "Goodbye!!!" << std::endl; exit(0); }
void Counter::set_initial_value(int initial_value) { this->initial_value = initial_value; }
