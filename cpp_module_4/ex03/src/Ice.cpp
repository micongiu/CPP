#include "../include/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice created" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	std::cout << "Created as a copy of Ice" << std::endl;
}

Ice& Ice::operator=( const Ice& src )
{
	std::cout << "Ice -assignation operator- called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
};

Ice::~Ice()
{
	std::cout << "Ice destroyed" << std::endl;
};

AMateria* Ice::clone() const
{
	std::cout << "Ice - clone - call" << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
