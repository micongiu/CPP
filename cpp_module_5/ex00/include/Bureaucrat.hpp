#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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

		const std::string getName();
		int getValue();

		void increaseGrade();
		void decreaseGrade();
	
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
