#pragma once
#include<string>
#include<iostream>

class Figure
{
public:
	Figure();
	Figure(std::string name_, int sides_count_);

	virtual bool is_correct() const;
	virtual void print_info();

protected:
	int sides_count;
	std::string name;
};