#include <iostream>

struct BankAccount
{
	long long savings_account;
	std::string beneficiary;
	double balance;
};

void change_the_balance(BankAccount& client1, double new_balance)
{
	client1.balance = new_balance;
}

int main()
{
	BankAccount client1;
	double new_balance;

	std::cout << "Enter savings account number: "; std::cin >> client1.savings_account;
	std::cout << "Enter a beneficiary: "; std::cin >> client1.beneficiary;
	std::cout << "Enter a balance: "; std::cin >> client1.balance;
	std::cout << "\nEnter a new balance: "; std::cin >> new_balance;
	change_the_balance(client1, new_balance);
	std::cout << "\nYour accaunt: " << client1.beneficiary << ", " << client1.savings_account << ", " << client1.balance << std::endl;
}