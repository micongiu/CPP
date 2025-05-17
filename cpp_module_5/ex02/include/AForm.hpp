#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _requiredSign;
		const int _requiredExecute;

	protected:
    	virtual void useForm() const = 0; 
		
	public:
		AForm(std::string name, int requiredSign, int requiredExecute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		~AForm();

		std::string getName() const;
		bool getSigned() const;
		int  getRequiredSign() const;
		int  getRequiredExecute() const;

		void setSigned(bool status);

		void beSigned(Bureaucrat& bur);

		void execute(Bureaucrat const & executor) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& src);

#endif