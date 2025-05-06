#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Defaul")
{
	std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : _type("Defaul")
{
	*this = src;
	std::cout << "WrongAnimal created as a copy of WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
};

void WrongAnimal::makeSound() const
{
	std::cout << "This WrongAnimal say somethig " << std::endl;
};

std::string WrongAnimal::getType() const
{
	return (this->_type);
};

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
};

