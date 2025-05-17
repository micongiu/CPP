#include <iostream>
#include "include/Bureaucrat.hpp"
#include "include/PresidentialPardonForm.hpp"
#include "include/RobotomyRequestForm.hpp"
#include "include/ShrubberyCreationForm.hpp"

int main()
{
    try {
    	std::cout << "--- Create a bureaucrat with a high enough grade --- " << "\n";
        Bureaucrat highLevel("Alice", 1);
		std::cout << "\n";

        std::cout << "--- Create a ShrubberyCreationForm and test signing and executing --- " << "\n";
        ShrubberyCreationForm shrubForm("home");
        std::cout << shrubForm << "\n";
        
        highLevel.signForm(shrubForm);
        highLevel.executeForm(shrubForm);
		std::cout << "\n";

        std::cout << "--- Create a RobotomyRequestForm and test signing and executing --- " << "\n";
        RobotomyRequestForm robotForm("Bender");
        std::cout << robotForm << "\n";
		std::cout << "\n";
        
        highLevel.signForm(robotForm);
        highLevel.executeForm(robotForm);
		std::cout << "\n";

        std::cout << "--- Create a PresidentialPardonForm and test signing and executing --- " << "\n";
        PresidentialPardonForm pardonForm("Ford Prefect");
        std::cout << pardonForm << "\n";
		std::cout << "\n";
        
        highLevel.signForm(pardonForm);
        highLevel.executeForm(pardonForm);
		std::cout << "\n";

        std::cout << "--- Create a bureaucrat with a low grade for testing exceptions --- " << "\n";
        Bureaucrat lowLevel("Bob", 150);
		std::cout << "\n";
		
        std::cout << "--- Attempt to execute the form with a low-level bureaucrat --- " << "\n";
        lowLevel.executeForm(shrubForm);   
    } 
	// Note: this catch block will only catch exceptions thrown by functions such as
	//       constructors, which don’t have a try-catch block inside them.
	catch (std::exception &e) 
	{
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    return 0;
}