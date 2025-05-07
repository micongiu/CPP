#include "include/Bureaucrat.hpp"

int main ()
{
	try
	{ 
		Bureaucrat bureaucrat1("Bob", 2);
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.increaseGrade();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.decreaseGrade();
		std::cout << bureaucrat1 << std::endl;
		bureaucrat1.increaseGrade();
		bureaucrat1.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{ 
		Bureaucrat bureaucrat2("Alice", 150);
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decreaseGrade();
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decreaseGrade();
		std::cout << bureaucrat2 << std::endl;
		std::cout << bureaucrat2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
