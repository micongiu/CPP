#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(std::string name, int requiredSign, int requiredExecute) :
	_name(name),
	_signed(false),
	_requiredSign(requiredSign),
	_requiredExecute(requiredExecute)
{
	if (this->_requiredSign > 150 || this->_requiredExecute > 150)
		throw GradeTooLowException();
	if (this->_requiredSign < 1 || this->_requiredExecute < 1)
		throw GradeTooHighException();

	std::cout << "AForm " << this->_name << " created" << '\n';
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed), _requiredSign(src._requiredSign), _requiredExecute(src._requiredExecute)
{
	std::cout << this->getName() << " created as a copy of AForm" << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << this->getName() << " assignation operator called" << std::endl;
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

AForm::AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destroyed" << '\n';
}

void AForm::beSigned(Bureaucrat& bur)
{
	if (this->getRequiredSign() < bur.getGrade())
		throw GradeTooLowException();
	
	this->setSigned(true);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int  AForm::getRequiredSign() const
{
	return (this->_requiredSign);
}

int  AForm::getRequiredExecute() const
{
	return (this->_requiredExecute);
}

void AForm::setSigned(bool status)
{
	this->_signed = status;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->getRequiredExecute() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw FormNotSignedException();
	
	this->useForm();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm_Error: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm_Error: Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form_Error: Form not signed");
}

std::ostream& operator<<(std::ostream& os, AForm& src)
{
	os << "AForm " << src.getName() << " \nstatus: ";
	if (src.getSigned())
		os << "signed";
	else
		os << "not signed.\n";
	os << "required grade to sign: " << src.getRequiredSign() << "\nrequired grade to execute: " << src.getRequiredExecute() << std::endl;

	return (os);
} 
