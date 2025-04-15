#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	this->_brain = new Brain;
	std::cout << this->getType() << " created" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	*this = src;
	this->_brain = new Brain;
	std::cout << this->getType() << " created as a copy of Dog" << std::endl;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
	{
		this->_type = src.getType();
		this->_brain = src._brain;
	}
	return (*this);
};

Dog::~Dog()
{
	std::cout << this->getType() << " destroyed" << std::endl;
	delete this->_brain;
};

void Dog::makeSound() const
{
	std::cout << this->getType() << ": 'Bau Bau'" << std::endl;
};
