#include "include/Array.hpp"

int main()
{
	try
	{
		Array<int> intArray(5);
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = static_cast<int>(i * 10);
		}

		std::cout <<"Contents of intArray" << std::endl;
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}

		Array<int> copiedArray = intArray;
		std::cout <<"\nContents of copiedArray" << std::endl;
		for (size_t i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
		}

		std::cout << "\nTrying out-of-bounds access..." << std::endl;
		std::cout << intArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in testIntArray: " << e.what() << std::endl;
	}

	std::cout << "\n--- Testing Array<std::string> ---" << std::endl;
	try
	{
		const Array<std::string> strArray(3);
		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "!";

		std::cout <<"Contents of strArray" << std::endl;
		for (size_t i = 0; i < strArray.size(); ++i)
		{
			std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
		}

		Array<std::string> copiedArray = strArray;
		std::cout <<"\nContents of copied strArray" << std::endl;
		for (size_t i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught in testStringArray: " << e.what() << std::endl;
	}

	return (0);
}