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
	
	std::cout << "--- Deep copying test ---" << std::endl;
	std::cout << "Creating a new Dog with a specific idea in its brain" << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea("Chase the cat", 0);
	std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "Copying the dog" << std::endl;
	Dog copiedDog(originalDog);
	std::cout << std::endl;

	std::cout << "Changing the idea of the original dog" << std::endl;
	originalDog.getBrain()->setIdea("I love cats", 0);
	std::cout << std::endl;

	std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "--- Deleting animals ---" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	return 0;
}