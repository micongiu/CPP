#include "Form.hpp"

Form::Form(std::string name, int requiredSign, int requiredExecute) :
	_name(name),
	_requiredSign(requiredSign),
	_requiredExecute(requiredExecute),
	_signed(false)
{
	if (this->_requiredSign > 150 || this->_requiredExecute > 150)
		throw GradeTooLowException();
	if (this->_requiredSign > 1 || this->_requiredExecute) > 1
		throw GradeTooHighException();

	std::cout << "Form" << this->_name << "created" << '\n';
}

Form::~Form()
{
	std::cout << "Form" << this->_name << "destroyed" << '\n';
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form_Error: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form_Error: Grade too low");
}
