#include "include/PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout <<GREEN "Enter a command(ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin >> std::ws, command))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
		{
			int	index;
			std::cout << "Enter an index: ";
			if (std::cin >> index)
			{
				std::cout << "You entered index: " << index << std::endl;
				phoneBook.search(index);
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "End of input. Exiting." << std::endl;
			break;
		}
		else
			std::cout <<RED "Command not found"<< std::endl;
	}
}
