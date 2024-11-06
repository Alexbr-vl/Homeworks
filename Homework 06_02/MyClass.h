#pragma once
#include<iostream>
#include <cstdlib>

class Counter
{
private: int initial_value;
public: Counter(); int plus(); int minus(); void print(); void quit(); void set_initial_value(int initial_value);
};
