#include <iostream>

enum Months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() 
{
    int number_of_month;

    while (true)
    {
        std::cout << "Enter month number(1-12), for break 0: ";
        std::cin >> number_of_month;

        if (number_of_month == 0) {
            break;
        }

        // Приводим ввод к типу перечисления Months
        Months month = static_cast<Months>(number_of_month);

        switch (month)
        {
        case January:
            std::cout << "January" << std::endl << std::endl;
            break;
        case February:
            std::cout << "February" << std::endl << std::endl;
            break;
        case March:
            std::cout << "March" << std::endl << std::endl;
            break;
        case April:
            std::cout << "April" << std::endl << std::endl;
            break;
        case May:
            std::cout << "May" << std::endl << std::endl;
            break;
        case June:
            std::cout << "June" << std::endl << std::endl;
            break;
        case July:
            std::cout << "July" << std::endl << std::endl;
            break;
        case August:
            std::cout << "August" << std::endl << std::endl;
            break;
        case September:
            std::cout << "September" << std::endl << std::endl;
            break;
        case October:
            std::cout << "October" << std::endl << std::endl;
            break;
        case November:
            std::cout << "November" << std::endl << std::endl;
            break;
        case December:
            std::cout << "December" << std::endl << std::endl;
            break;
        default:
            std::cout << "Error!!! Enter correct number (1-12)." << std::endl<< std::endl;
            break;
        }
    }
    std::cout << "Goodbye!" << std::endl;
}
