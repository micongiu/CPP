#include "../include/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure created" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	std::cout << "Created as a copy of Cure" << std::endl;
}

Cure& Cure::operator=( const Cure& src )
{
	std::cout << "Cure -assignation operator- called" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
};

Cure::~Cure()
{
	std::cout << "Cure destroyed" << std::endl;
};

AMateria* Cure::clone() const
{
	std::cout << "Cure - clone - call" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
