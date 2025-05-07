#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << this->getName() << " created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << this->getName() << " created" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << this->getName() << " created as a copy of Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src )
{
	std::cout << this->getName() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " destroyed" << std::endl;
}

const std::string Bureaucrat::getName()
{
	return (this->_name);
}

int Bureaucrat::getValue()
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

void Bureaucrat::increaseGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();

	this->_grade--;
}	

void Bureaucrat::decreaseGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src)
{
	os << src.getName() << ", Bureaucrat grade " << src.getValue();
	return os;
}
