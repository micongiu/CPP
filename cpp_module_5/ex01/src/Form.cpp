#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(std::string name, int requiredSign, int requiredExecute) :
	_name(name),
	_signed(false),
	_requiredSign(requiredSign),
	_requiredExecute(requiredExecute)
{
	if (this->_requiredSign > 150 || this->_requiredExecute > 150)
		throw GradeTooLowException();
	if (this->_requiredSign > 1 || this->_requiredExecute > 1)
		throw GradeTooHighException();

	std::cout << "Form " << this->_name << " created" << '\n';
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _requiredSign(src._requiredSign), _requiredExecute(src._requiredExecute)
{
	std::cout << this->getName() << " created as a copy of Form" << std::endl;
}

Form& Form::operator=(const Form& src)
{
	std::cout << this->getName() << " assignation operator called" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

Form::Form::~Form()
{
	std::cout << "Form " << this->_name << " destroyed" << '\n';
}

void Form::beSigned(Bureaucrat& bur)
{
	if (this->getRequiredSign() >= bur.getValue())
		throw GradeTooLowException();
	
	this->setSigned(true);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int  Form::getRequiredSign() const
{
	return (this->_requiredSign);
}

int  Form::getRequiredExecute() const
{
	return (this->_requiredExecute);
}

void Form::setSigned(bool status)
{
	this->_signed = status;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form_Error: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form_Error: Grade too low");
}

std::ostream& operator<<(std::ostream& os, Form& src)
{
	os << "Form " << src.getName() << " \nstatus: ";
	if (src.getSigned())
		os << "signed";
	else
		os << "not signed.\n";
	os << "required grade to sign: " << src.getRequiredSign() << "\nrequired grade to execute: " << src.getRequiredExecute() << std::endl;

	return (os);
} 
