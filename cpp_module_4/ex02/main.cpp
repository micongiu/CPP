#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	std::cout << "Animal object creation: " << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	std::cout << std::endl;

	std::cout << "--- Creating " << arraySize / 2 << " new Dog ---" << std::endl;
	for (int i = 0; i < arraySize / 2; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	std::cout << "--- Creating " << arraySize / 2 << " new Cat ---" << std::endl;
	for (int i = arraySize / 2; i < arraySize; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	std::cout << "--- Making sounds ---" << std::endl;
	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();
	std::cout << std::endl;
	
	std::cout << "--- Tring to instantiate Animal ---" << std::endl;
	// Animal animal; // Error: cannot instantiate abstract class
	std::cout << "main.cpp:29:16: error: cannot declare variable ‘animal’ to be of abstract type ‘Animal’" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Deleting animals ---" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	return 0;
}