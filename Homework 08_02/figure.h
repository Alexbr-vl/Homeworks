#pragma once
#include<string>
#include<iostream>

class Figure
{
public:
	Figure();
	Figure(const std::string& name_, int sides_count_);

	virtual void print_info() const;

protected:
	int sides_count;
	std::string name;
};