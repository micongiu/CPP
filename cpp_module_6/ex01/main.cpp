#include "include/Serialization.hpp"

void loadCharacter(Data *character)
{
	character->name = "Salazar";
	character->surName = "slytherin";
	character->age = 82;
}

void displayData(const Data *character)
{
	std::cout << "Name: " << character->name << std::endl;
	std::cout << "surName: " << character->surName << std::endl;
	std::cout << "age: " << character->age << std::endl;
}

bool compareData(const Data *a, const Data *b)
{
	return (a->name == b->name &&
			a->surName == b->surName &&
			a->age == b->age);
}

int main()
{
	Data character;
	loadCharacter(&character);

	Data *original_ptr = &character;
	std::cout << std::hex;

	std::cout << "Original character address: " << original_ptr << std::endl;
	displayData(original_ptr);

	// Serialize
	uintptr_t serialized_ptr = Serialization::serialize(original_ptr);
	std::cout << "\nSerialization:\n" << std::endl;
	std::cout << "Serialized uintptr_t:\t" << serialized_ptr << std::endl;

	// Deserialize
	Data *deserialized_ptr = Serialization::deserialize(serialized_ptr);
	std::cout << "\nDeserialization:\n" << std::endl;
	std::cout << "Deserialized character address:\t" << deserialized_ptr << std::endl;
	displayData(deserialized_ptr);

	// Verifications
	std::cout << "\nVerification:\n" << std::endl;
	std::cout << "Pointers match:\t" << ((original_ptr == deserialized_ptr) ? "true" : "false") << std::endl;
	std::cout << "Data matches:\t" << (compareData(original_ptr, deserialized_ptr) ? "true" : "false") << std::endl;

	return (0);
}
