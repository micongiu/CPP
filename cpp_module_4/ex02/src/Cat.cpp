#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->setType("Cat");
	this->_brain = new Brain;
	std::cout << this->getType() << " created" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	this->_brain = new Brain(*src._brain);
	std::cout << this->getType() << " created as a copy of Cat" << std::endl;
}

Cat& Cat::operator=( const Cat& src )
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

Cat::~Cat()
{
	std::cout << this->getType() << " destroyed" << std::endl;
	if (this->_brain)
		delete this->_brain;
};

Brain* Cat::getBrain() const
{
	return (this->_brain);
}

void Cat::makeSound() const
{
	std::cout << this->getType() << ": 'Bau Bau'" << std::endl;
};
