#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main()
{
	std::cout << "--- Test 1: Create a form with a grade too high ---" << '\n';
	try
	{
		std::cout << "1)" <<'\n';
		Form form("FormA", 0, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
    std::cout << '\n';

	std::cout << "--- Test 2: Create a form with a grade too low ---" << '\n';
	try
	{
		std::cout << "1)" <<'\n';
		Form form("FormA", 151, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception - 1 caught: " << e.what() << '\n';
	}
    std::cout << '\n';

	std::cout << "--- Test 3: Create Bureaucrats and valid forms ---" << '\n';
    try
    {
		std::cout << "1)" <<'\n';
        Bureaucrat highRank("Alice", 1);
        std::cout << highRank << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating highRank: " << e.what() << '\n';
    }

    try
    {
		std::cout << "2)" <<'\n';
        Bureaucrat lowRank("Bob", 150);
        std::cout << lowRank << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating lowRank: " << e.what() << '\n';
    }

    try
    {
		std::cout << "3)" <<'\n';
        Form formA("FormA", 50, 25);
        std::cout << formA;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating formA: " << e.what() << '\n';
    }

    try
    {
		std::cout << "4)" <<'\n';
        Form formB("FormB", 1, 1);
        std::cout << formB;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating formB: " << e.what() << '\n';
    }

    std::cout << '\n';
	std::cout << "--- Test 4: Sign forms ---" << '\n';
    try
    {
		std::cout << "1)" <<'\n';
        Bureaucrat highRank("Alice", 1);
        Form formA("FormA", 50, 25);
        highRank.signForm(formA);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while highRank signing formA: " << e.what() << '\n';
    }

    try
    {
		std::cout << "2)" <<'\n';
        Bureaucrat lowRank("Bob", 150);
        Form formB("FormB", 1, 1);
        lowRank.signForm(formB);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while lowRank signing formB: " << e.what() << '\n';
    }

    try
    {
		std::cout << "3)" <<'\n';
        Bureaucrat highRank("Alice", 1);
        Form formB("FormB", 1, 1);
        highRank.signForm(formB);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while highRank signing formB: " << e.what() << '\n';
    }

    return 0;
}
