#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->setType("Dog");
	std::cout << this->getType() << " created" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
	*this = src;
	std::cout << this->getType() << " created as a copy of Dog" << std::endl;
}

Dog& Dog::operator=( const Dog& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
};

Dog::~Dog()
{
	std::cout << this->getType() << " destroyed" << std::endl;
};

void Dog::makeSound() const
{
	std::cout << this->getType() << ": 'Bau Bau'" << std::endl;
};
