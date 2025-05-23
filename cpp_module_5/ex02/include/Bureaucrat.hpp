#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat& src );
		Bureaucrat& operator=( const Bureaucrat& src );
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();

		void signForm(AForm& form);
		void executeForm(AForm& form) const;
	
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
	
		class GradeTooLowException : public std::exception
		{
			public :
			   virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& src);

#endif
