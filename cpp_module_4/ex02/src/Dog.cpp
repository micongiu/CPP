#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	this->_brain = new Brain;
	std::cout << this->getType() << " created" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << this->getType() << " created as a copy of Dog" << std::endl;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
};

Dog::~Dog()
{
	std::cout << this->getType() << " destroyed" << std::endl;
	if (this->_brain)
		delete this->_brain;
};

Brain* Dog::getBrain() const
{
	return (this->_brain);
}

void Dog::makeSound() const
{
	std::cout << this->getType() << ": 'Bau Bau'" << std::endl;
};
