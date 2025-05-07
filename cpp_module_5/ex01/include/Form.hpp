#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _requiredSign;
		const int _requiredExecute;

	public:
		Form(std::string name, int requiredSign, int requiredExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int  getRequiredSign() const;
		int  getRequiredExecute() const;

		void setSigned(bool status);

		void beSigned(Bureaucrat& bur);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form& src);

#endif