#include <iostream>
#include <fstream>
#include<string>

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

	std::string get_output_address () { return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(flat_number); }
	std::string get_city() const { return city; }
};

void clear_memory(Address** address_array, int number_of_addresses) {
	for (int i = 0; i < number_of_addresses; ++i) {
		delete address_array[i];
	}
	delete[] address_array;
}
void sort_addresses(Address** addresses, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (addresses[j]->get_city() > addresses[j + 1]->get_city()) {
				// Меняем местами указатели на адреса
				Address* temp = addresses[j];
				addresses[j] = addresses[j + 1];
				addresses[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int number_of_addresses = 0;
	std::ifstream in_file;
	in_file.open("in.txt");

	if (in_file.is_open())
	{
		in_file >> number_of_addresses;

		Address** address_array = new Address * [number_of_addresses]; //авансируем память

		for (int i = 0; i < number_of_addresses; i++)  //заполняем массив
		{
			std::string city_, street_;
			int house_number_, flat_number_;

			in_file >> city_ >> street_ >> house_number_ >> flat_number_; //сохраняем данные из файла в переменные
			
			// Создаём новый объект Address и сохраняем его указатель в массиве
			address_array[i] = new Address(city_, street_, house_number_, flat_number_);
		}
		in_file.close(); //закрываем файл
		
		sort_addresses(address_array, number_of_addresses); //делаем пузырьковую сортировку

		std::ofstream out_file;
		out_file.open("out.txt");

		if (out_file.is_open()) //если файл открыли, сохраняем в него данные из массива
		{
			out_file << number_of_addresses << std::endl;

			for (int i = 0; i < number_of_addresses; i++) {
				out_file << address_array[i]->get_output_address() << std::endl;
			}
			out_file.close(); //закрываем файл
			clear_memory(address_array, number_of_addresses);//чистим память
		}
		else
		{
			std::cout << "File is not opened" << std::endl;
			clear_memory(address_array, number_of_addresses); //чистим память даже если файл на запись открыть не удалось
		}
	}
	else { std::cout << "File is not opened" << std::endl; }
}