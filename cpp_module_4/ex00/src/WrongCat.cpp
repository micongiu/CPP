#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->setType("WrongCat");
	std::cout << this->getType() << " created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	*this = src;
	std::cout << this->getType() << " created as a copy of WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& src )
{
	std::cout << this->getType() << " -assignation operator- called" << std::endl;
	if (this != &src)
		this->_type = src.getType();
	return (*this);
};

WrongCat::~WrongCat()
{
	std::cout << this->getType() << " destroyed" << std::endl;
};

void WrongCat::makeSound() const
{
	std::cout << this->getType() << ": 'Bau Bau'" << std::endl;
};
