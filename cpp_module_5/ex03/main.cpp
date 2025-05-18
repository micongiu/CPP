#include <iostream>
#include "include/Intern.hpp"

int main()
{
	Intern intern;
	AForm* form;

	std::cout << "=== Test case 1: Creating a RobotomyRequestForm ===" << std::endl;
	form = intern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << "Successfully created: " << form->getName() << std::endl;
		delete form;
	}
	std::cout << std::endl;

	std::cout << "=== Test case 2: Creating a ShrubberyCreationForm ===" << std::endl;
	form = intern.makeForm("shrubbery creation", "Garden");
	if (form)
	{
		std::cout << "Successfully created: " << form->getName() << std::endl;
		delete form;
	}
	std::cout << std::endl;

	std::cout << "=== Test case 3: Creating a PresidentialPardonForm ===" << std::endl;
	form = intern.makeForm("presidential pardon", "Alice");
	if (form)
	{
		std::cout << "Successfully created: " << form->getName() << std::endl;
		delete form;
	}
	std::cout << std::endl;

	std::cout << "=== Test case 4: Trying to create an unknown form ===" << std::endl;
	form = intern.makeForm("unknown form", "Target");
	if (!form)
		std::cout << "Failed to create form due to unknown name." << std::endl;

	return 0;
}