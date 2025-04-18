#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog( const Dog& src );
		Dog& operator=( const Dog& src );
		~Dog();

		Brain* getBrain() const;
		void makeSound() const;
};

#endif
