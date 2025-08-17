#include "include/span.hpp"

int main() {
	std::cout << "--- Test 1: Basic Functionality ---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Test 2: MaxNumber Exception ---" << std::endl;
	Span sp2 = Span(3);
	sp2.addNumber(1);
	sp2.addNumber(2);
	sp2.addNumber(3);
	try {
		std::cout << "Trying to add a 4th number to a Span of size 3..." << std::endl;
		sp2.addNumber(4);
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Test 3: NoElementFound Exception ---" << std::endl;
	Span sp3 = Span(10);
	try {
		std::cout << "Trying to find shortest span in an empty Span..." << std::endl;
		sp3.shortestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "Trying to find longest span in an empty Span..." << std::endl;
		sp3.longestSpan();
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Test 4: Span with one element ---" << std::endl;
	Span sp4 = Span(5);
	sp4.addNumber(42);
	try {
		std::cout << "Trying to find shortest span with one number..." << std::endl;
		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "Trying to find longest span with one number..." << std::endl;
		std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Test 5: Large Number of Elements ---" << std::endl;
	try {
		Span sp5 = Span(15000);
		std::vector<int> numbers;
		for (int i = 0; i < 15000; ++i)
		{
			numbers.push_back(i);
		}

		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
			sp5.addNumber(*it);
		}

		std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}

	return 0;
}