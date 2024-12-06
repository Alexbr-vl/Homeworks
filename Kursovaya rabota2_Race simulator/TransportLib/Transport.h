#pragma once
#include<string>

class Transport
{
protected:
	double speed_;
	std::string name_;
public:
	Transport(const std::string& name, double speed);

	virtual double time_of_distance(double distance) const = 0;

	std::string get_name() const;

	// Проверка типа транспорта
	virtual bool is_ground_transport() const;
	virtual bool is_air_transport() const;
};