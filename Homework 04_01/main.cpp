#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
bool is_number(const std::string& str) {
	std::istringstream iss(str);
	int num;
	return (iss >> num) && (iss.eof());
}

int main()
{
	std::ifstream in_file;
	in_file.open("in.txt");
	
	int number_of_addresses=0;

	if (in_file.is_open())
	{
		in_file >> number_of_addresses; // количество адресов из файла
		int actual_number_of_addresses = 0; // счётчик реального количества адресов
		
		Address** address_array = new Address* [number_of_addresses];   //авансировали память на двумерный массив

				
		for (int i = 0; i < number_of_addresses; i++)  //заполняем массив
		{
				std::string city_, street_, house_number_string, flat_number_string;
				int house_number_, flat_number_;
				
				if (!(in_file >> city_ >> street_ >> house_number_string >> flat_number_string))// проверяем соответствует количество итераций количеству информации в файле, если не соответствует прерываем
				{
					std::cout << "There is not enough data in the file" << std::endl;
					break;
				}
				if (!is_number(house_number_string) || !is_number(flat_number_string)) // проверяем соответствует ли формат ввода номера дома и номера квартиры, если не соответствует прерываем
				{
					std::cout << "ERROR!!! Invalid format \"Number of house\" or \"number of flat\"" << std::endl;
					break;
				}

				// Преобразуем строки в числа
				house_number_ = std::stoi(house_number_string);
				flat_number_ = std::stoi(flat_number_string);

				address_array[actual_number_of_addresses] = new Address(city_, street_, house_number_, flat_number_);
				++actual_number_of_addresses;
		}
		in_file.close(); //закрываем файл

		if (actual_number_of_addresses < number_of_addresses) 
		{
			std::cout << "ERROR! There are less real addresses than specified in the file or format \"Number of house\" or \"number of flat\" is incorrect. Check the file \"in.txt\"." << std::endl;
			// clear_memory(address_array, actual_number_of_addresses);   если почистить память тут, то выдает исключение "ошибка доступа", получается что ссылается на уже удаленный объект
		}

		
		std::ofstream out_file;
		out_file.open("out.txt");

		if (out_file.is_open())
		{
			out_file << actual_number_of_addresses << std::endl;

			for (int i = actual_number_of_addresses - 1; i >= 0; --i) {
				out_file << address_array[i]->get_output_address() << std::endl;
			}
			out_file.close(); //закрываем файл
			clear_memory(address_array, actual_number_of_addresses);
		}
		else
		{
			std::cout << "File is not opened" << std::endl;
			clear_memory(address_array, actual_number_of_addresses);
		}
	}
	else
	{
		std::cout << "File is not opened" << std::endl;
	}
}