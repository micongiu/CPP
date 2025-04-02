#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	// Printing the address of 'value'
	std::cout << "Address of brain: " << &brain << std::endl;

    // Printing the address stored in the pointer 'ptr'
    std::cout << "Address stored in stringPTR: " << stringPTR << std::endl;

    // Printing the address that the reference 'ref' refers to.
    std::cout << "Address referred to by stringREF: " << &stringREF << std::endl;

	std::cout << "brain: " << brain << std::endl;

	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	std::cout << "Reference stringREF: " << stringREF << std::endl;
}
