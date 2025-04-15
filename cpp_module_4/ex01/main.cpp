#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	std::cout << " --- CORRECT ANIMAL --- " << std::endl;
	std::cout << "Animal object creation: " << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;

	std::cout << "Dog object creation: " << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;

	std::cout << "Cat object creation: " << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "getType calls from Dog and Cat: " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	
	std::cout << "makeSound calls from Dog, Cat and Animal: " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Deleting objects: " << std::endl;
	std::cout << "Animal object destruction: " << std::endl;
	delete meta;
	std::cout << std::endl;

	std::cout << "Dog object destruction: " << std::endl;
	delete j;
	std::cout << std::endl;

	std::cout << "Cat object destruction: " << std::endl;
	delete i;

	return 0;
}