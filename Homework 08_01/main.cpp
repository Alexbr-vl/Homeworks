#include<iostream>
#include<string>
#include <windows.h>

class Bad_length :public std::exception
{
public:
	const char* what() const override { return "Вы ввели слово запретной длины!"; }
};

int function(const std::string& str, int forbidden_length)
{
	if (str.length() == forbidden_length)
	{
		throw Bad_length();
	}
	return str.length();
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int forbidden_length;
	std::string str;

	std::cout << "Введите запретную длину: "; std::cin >> forbidden_length;

	while(true)
	{
		std::cout << "Введите слово: ";  std::cin >> str;
		try
		{
			std::cout << "Длина слова \"" << str << "\" равна " << function(str, forbidden_length) << std::endl;
		}
		catch (Bad_length& e)
		{
			std::cout << e.what() << " До свидания!" << std::endl;
			break;
		}
	} 
}