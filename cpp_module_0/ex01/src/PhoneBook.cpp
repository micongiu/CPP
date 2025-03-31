#include "../include/PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook()
{
	this->indexCount = 0;
};

PhoneBook::~PhoneBook()
{
};

// Add function

void	PhoneBook::addFirstName(int index)
{
	std::string fistName;

	while (1)
	{	
		std::cout <<BLUE "Enter the fistName: ";
		if (!std::getline(std::cin >> std::ws, fistName))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (fistName.empty() || fistName == "\"\"")
		{
			std::cout <<RED "The fistName can not be void"<< std::endl;
		}
		else
		{
			this->contacts[index].setFirstName(fistName);
			break;
		}
	}
};

void	PhoneBook::addLastName(int index)
{
	std::string lastNane;

	while (1)
	{	
		std::cout <<BLUE "Enter the lastNane: ";
		if (!std::getline(std::cin >> std::ws, lastNane))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (lastNane.empty() || lastNane == "\"\"")
		{
			std::cout <<RED "The lastNane can not be void"<< std::endl;
		}
		else
		{
			this->contacts[index].setLastName(lastNane);
			break;
		}
	}
};

void	PhoneBook::addNickname(int index)
{
	std::string nickname;

	while (1)
	{	
		std::cout <<BLUE "Enter the nickname: ";
		if (!std::getline(std::cin >> std::ws, nickname))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (nickname.empty() || nickname == "\"\"")
		{
			std::cout <<RED "The nickname can not be void"<< std::endl;
		}
		else
		{
			this->contacts[index].setNickname(nickname);
			break;
		}
	}
};

void	PhoneBook::addPhoneNumber(int index)
{
	std::string phoneNumber;
	bool validNumber = false;

	while (1)
	{	
		std::cout <<BLUE "Enter the phoneNumber: ";
		if (!std::getline(std::cin >> std::ws, phoneNumber))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (phoneNumber.empty() || phoneNumber == "\"\"")
		{
			std::cout <<RED "The phoneNumber can not be void"<< std::endl;
		}
		else
		{
			validNumber = true;
			for (size_t i = 0; phoneNumber[i]; i++)
			{
				if (!std::isdigit(phoneNumber[i]))
				{
					validNumber = false;
					std::cout << RED "The phoneNumber must contain only digits" << std::endl;
					break;
				}
			}
		}
		if (validNumber)
		{
			this->contacts[index].setPhoneNumber(phoneNumber);
			break;
		}
	}
};

void	PhoneBook::addDarkestSecret(int index)
{
	std::string darkestSecret;

	while (1)
	{	
		std::cout <<BLUE "Enter the darkestSecret: ";
		if (!std::getline(std::cin >> std::ws, darkestSecret))
		{
			if (std::cin.eof())
			{
				std::cout << "End of input. Exiting." << std::endl;
				break;
			}
		}
		if (darkestSecret.empty() || darkestSecret == "\"\"")
		{
			std::cout <<RED "The darkestSecret can not be void"<< std::endl;
		}
		else
		{
			this->contacts[index].setDarkestSecret(darkestSecret);
			break;
		}
	}
};

void	PhoneBook::add()
{
	int index;
	static int overwriteIndex = 0;

	if (this->indexCount == 8)
	{
		std::cout<<WHITE "Max number of contact reached, the oldest will be overwrite"<< std::endl;
		index = overwriteIndex;
		overwriteIndex = (overwriteIndex + 1) % 8;
	}
	else
	{
		index = this->indexCount;
		this->indexCount++;
	}
	addFirstName(index);
	addLastName(index);
	addNickname(index);
	addPhoneNumber(index);
	addDarkestSecret(index);
	std::cout <<GREEN "Contact added successfully!" << std::endl;
};

void	PhoneBook::search(int index)
{
	if (this->indexCount == 0)
	{
		std::cout <<RED "Contact is empty" << std::endl;
		return;
	}
	if ((index < 0) | (index > 7))
	{
		std::cout <<RED "Index must be between 1 and 8" << std::endl;
		return;
	}
	std::cout << "name : " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "last name : " << this->contacts[index].getLastName() << std::endl;
	std::cout << "nickname : " << this->contacts[index].getNickName() << std::endl;
	std::cout << "phone number : " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "dark secret :" << this->contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
