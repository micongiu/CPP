#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal( const Animal& src );
		Animal& operator=( const Animal& src );
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;
		void setType(std::string type);
};

#endif
