#include "../include/Animal.hpp"

Animal::Animal() : _type("Defaul")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& src) : _type("Defaul")
{
	*this = src;
	std::cout << "Animal created as a copy of Animal" << std::endl;
}

Animal& Animal::operator=( const Animal& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
};

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
};

std::string Animal::getType() const
{
	return (this->_type);
};

void Animal::setType(std::string type)
{
	this->_type = type;
};

