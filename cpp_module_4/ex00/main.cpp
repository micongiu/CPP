#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

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

	std::cout << std::endl << std::endl;
	std::cout << " ------------------------------ " << std::endl;
	std::cout << " --- WRONG ANIMAL --- " << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "WrongCat object creation: " << std::endl;
	const WrongAnimal* j2 = new WrongCat();
	std::cout << std::endl;
	
	std::cout << "getType calls from WrongCat: " << std::endl;
	std::cout << j2->getType() << " ";
	std::cout << "makeSound calls from WrongCat: ";
	j2->makeSound(); //will output the wrongAnimal sound!
	std::cout << "makeSound call from the WrongCat object: ";
	meta2->makeSound();
	std::cout << std::endl;

	std::cout << "WrongAnimal object destruction: " << std::endl;
	delete meta2;
	std::cout << std::endl;

	std::cout << "WrongCat object destruction:" << std::endl;
	delete j2;

	return 0;
}
