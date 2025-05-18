#ifndef INTERN_CPP
# define INTERN_CPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		std::string formNames[3];

	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=( const Intern& src );
		~Intern();

		AForm* makeForm( std::string formName, std::string target);
};

#endif