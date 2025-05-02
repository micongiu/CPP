#include "../include/AMateria.hpp"

AMateria::AMateria() : _type("Defaul")
{
	std::cout << "AMateria created" << std::endl;
}

AMateria::AMateria(const AMateria& src) : _type(src._type)
{
	std::cout << "AMateria created as a copy of AMateria" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	(void) type;
	std::cout << "AMateria created" << std::endl;
}

AMateria& AMateria::operator=( const AMateria& src )
{
	(void)src;
	std::cout << "AMateria -assignation operator- called" << std::endl;
	return (*this);
};

AMateria::~AMateria()
{
	std::cout << "AMateria destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
