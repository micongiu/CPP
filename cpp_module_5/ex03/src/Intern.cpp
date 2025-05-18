#include "../include/Intern.hpp"

Intern::Intern()
{
	formNames[0] = "presidential pardon";
	formNames[1] = "robotomy request";
	formNames[2] = "shrubbery creation";
	std::cout << "Intern created" << "\n";
}

Intern::Intern(const Intern& src)
{
	formNames[0] = "presidential pardon";
    formNames[1] = "robotomy request";
    formNames[2] = "shrubbery creation";
	(void)src;
	std::cout << "Intern created as a copy of Intern" << "\n";
}

Intern& Intern::operator=( const Intern& src )
{
	std::cout << "Intern -assignation operator- called" << "\n";
	(void)src;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << "\n";
}

AForm* Intern::makeForm( std::string formName, std::string target)
{
	int formType = 3;
	for (size_t i = 0; i < 4; i++)
	{
		if (formName == this->formNames[i])
			formType = i;
	}

	switch (formType)
	{
		case 0:
			std::cout << "Intern creates PresidentialPardonForm" << "\n";
			return (new PresidentialPardonForm(target));
			break;
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << "\n";
			return (new RobotomyRequestForm(target));
			break;
		case 2:
			std::cout << "Intern creates ShrubberyCreationForm" << "\n";
			return (new ShrubberyCreationForm(target));
			break;
		
		default:
		 	std::cout << "Error: Form \"" << formName << "\" not found." << "\n";
            return (NULL);        
			break;
	}
}
