#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << "\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << this->getName() << " assignation operator called" << "\n";
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << "\n";
}

int rand50()
{
	return rand() & 1;
}

void RobotomyRequestForm::useForm() const
{
	srand(time(0));
	std::cout << "Drilling noises.... " << "\n";
	if (rand50() == 0)
		std::cout << this->_target << " has been robotomized successfully" << "\n";
	else
		std::cout << this->_target << " has been not robotomized successfully" << "\n";
}
