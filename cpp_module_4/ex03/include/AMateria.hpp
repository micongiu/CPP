#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		const std::string _type;

	public:
		AMateria();
		AMateria( const AMateria& src );
		AMateria( const std::string & type);
		AMateria& operator=( const AMateria& src );
		virtual ~AMateria();

		const std::string & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
