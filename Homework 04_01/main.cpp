#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
	std::string city;
	std::string street;
	int house_number;
	int flat_number;
public:
	Address (std::string city_, std::string street_, int house_number_, int flat_number_) 
	:city(city_), street(street_), house_number(house_number_), flat_number(flat_number_){}
	
	std::string get_output_address() const {
		return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(flat_number);
	}
};
void clear_memory(Address** address_array, int number_of_addresses) {
	for (int i = 0; i < number_of_addresses; ++i) {
		delete address_array[i];
	}
	delete[] address_array;
}


int main()
{
	std::ifstream in_file;
	in_file.open("in.txt");
	
	int number_of_addresses=0;

	if (in_file.is_open())
	{
		in_file >> number_of_addresses;
		
		Address** address_array = new Address* [number_of_addresses];   //авансировали пам€ть на двумерный массив
				
		for (int i = 0; i < number_of_addresses; i++)  //заполн€ем массив
		{
			std::string city_, street_;
			int house_number_, flat_number_;
			in_file >> city_ >> street_ >> house_number_ >> flat_number_;
			address_array[i] = new Address(city_, street_, house_number_, flat_number_);
		}
		in_file.close(); //закрываем файл
		
		std::ofstream out_file;
		out_file.open("out.txt");

		if (out_file.is_open())
		{
			out_file << number_of_addresses << std::endl;

			for (int i = number_of_addresses - 1; i >= 0; --i) {
				out_file << address_array[i]->get_output_address() << std::endl;
			}
			out_file.close(); //закрываем файл
			clear_memory(address_array, number_of_addresses);
		}
		else
		{
			std::cout << "File is not opened" << std::endl;
			clear_memory(address_array, number_of_addresses);
		}
	}
	else
	{
		std::cout << "File is not opened" << std::endl;
	}
}