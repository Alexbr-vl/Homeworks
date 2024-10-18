#include <iostream>


struct adress
{
	std::string city;
	std::string street;
	int house_number;
	int flat_number;
	int index;
};

void printAdress(adress* adress_array)
{
	for (int i = 0; i < 3; i++) 
	{
		std::cout << "city: " << adress_array[i].city << std::endl;
		std::cout << "Street: " << adress_array[i].street << std::endl;
		std::cout << "House number: " << adress_array[i].house_number << std::endl;
		std::cout << "Flat number: " << adress_array[i].flat_number << std::endl;
		std::cout << "Index: " << adress_array[i].index << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

int main()
{
	adress* adress_array = new adress[3];
	adress_array[0] = { "Vladivostok", "Uspenskogo", 108, 45, 690025 };
	adress_array[1] = { "Moscow", "Arbat", 1, 10, 119002 };
	adress_array[2] = { "Saint-Petersburg", "Dumskaya", 12, 34, 191186 };
	printAdress(adress_array);
}