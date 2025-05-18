#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

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

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
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

void Bureaucrat::signForm(AForm& form)
{
	if (form.getSigned())
	{
		std::cout << "Form " << form.getName() << " is already signed" << std::endl;
		return ;
	}
	
	try
	{
		form.beSigned(*this);
		std::cout << "Bureaucrat " << Bureaucrat::getName() << " signs " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Form " << form.getName() << " cannot be signed by " << Bureaucrat::getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->getName() << " executes " << form.getName() << "\n";
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << "Bureaucrat " << this->getName() << " can not executes " << form.getName() << "\n" << e.what() << "\n";
	}
	catch (AForm::FormNotSignedException& e)
	{
		std::cout << "AForm: " << form.getName() << "not valid" << "\n" << e.what() << "\n";
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& src)
{
	os << src.getName() << ", Bureaucrat grade " << src.getGrade();
	return os;
}
