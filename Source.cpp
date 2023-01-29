#include <iostream>

int choice;
std::string reg_name;
std::string reg_password;
std::string check1_password;
std::string check2_password;
std::string login_name;
std::string login_password;

int main();

void user_login() {
	std::cout << "Enter your nickname: ";
	std::cin >> login_name;

	std::cout << "Enter your password: ";
	std::cin >> login_password;

	if (login_name != reg_name || login_password != reg_password) {
		std::cout << "Incorrect nickname or password!\n";
		user_login();
	}

	std::cout << "You are logged in!\n";
	main();
}

void user_registration() {

	do {
		std::cout << "Enter your nickname: ";
		std::cin >> reg_name;
	} while (reg_name.empty());

	do {
		std::cout << "(1)Enter your password: ";
		std::cin >> check1_password;

		std::cout << "(2)Re-enter your password: ";
		std::cin >> check2_password;
	} while (check1_password != check2_password);

	reg_password = check2_password;

	std::cout << "Registration complete!\n";
	main();
}

int main() {

	std::cout << "1 for Login, 2 for Registration: ";
	std::cin >> choice;

	while (true) {
		if (choice == 1) {
			user_login();
		}
		else if (choice == 2) {
			user_registration();
		}
		else {
			std::cout << "Invalid input!\n" << "1 for Login, 2 for Registration: ";
			std::cin >> choice;
		}
	}

	return 0;
}