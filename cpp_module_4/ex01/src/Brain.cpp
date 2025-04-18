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
	if(this != &src)
	{
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
};

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
};

void Brain::setIdea( std::string idea, int index )
{
	this->_ideas[index] = idea;
};

std::string Brain::getIdea( int idea )
{
	return(this->_ideas[idea]);
};
