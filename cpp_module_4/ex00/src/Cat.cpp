#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->setType("Cat");
	std::cout << this->getType() << " created" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	*this = src;
	std::cout << this->getType() << " created as a copy of Cat" << std::endl;
}

Cat& Cat::operator=( const Cat& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
};

Cat::~Cat()
{
	std::cout << this->getType() << " destroyed" << std::endl;
};

void Cat::makeSound() const
{
	std::cout << this->getType() << ": 'Miao Miao'" << std::endl;
};
