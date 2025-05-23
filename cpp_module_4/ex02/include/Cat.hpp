#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat( const Cat& src );
		Cat& operator=( const Cat& src );
		~Cat();

		Brain* getBrain() const;
		void makeSound() const;
};

#endif
