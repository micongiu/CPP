#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Brain created as a copy of Brain" << std::endl;
}

Brain& Brain::operator=( const Brain& src )
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	return (*this);
};

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
};
