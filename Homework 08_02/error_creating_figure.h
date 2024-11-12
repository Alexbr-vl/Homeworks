#pragma once
#include<string>
#include<iostream>

class Incorrect_figure_data : public std::domain_error
{
public:
	Incorrect_figure_data(const std::string& msg) : std::domain_error(msg) {}
};