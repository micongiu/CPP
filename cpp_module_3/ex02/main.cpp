#include "include/FragTrap.hpp"

int main()
{
	std::cout << "--- Test FragTrap ---" << std::endl;
	FragTrap FragTrap("FRAGGY");

	std::cout << std::endl << "--- Test Attack ---" << std::endl;
    FragTrap.attack("Target3");
    FragTrap.takeDamage(5);

	std::cout << std::endl << "--- Test Repair ---" << std::endl;
    FragTrap.beRepaired(5);

	std::cout << std::endl << "--- Test HighFivesGuys ---" << std::endl;
    FragTrap.highFivesGuys();
    FragTrap.attack("Target4");

    return 0;
}