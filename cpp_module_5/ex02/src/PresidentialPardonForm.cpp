#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << "\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << this->getName() << " assignation operator called" << "\n";
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << "\n";
}

void PresidentialPardonForm::useForm() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << "\n";
}
