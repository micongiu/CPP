#include "include/ScavTrap.hpp"

int main()
{
	std::cout << "--- Test ScavTrap ---" << std::endl;
	ScavTrap ScavTrap("SCAVY");

	std::cout << std::endl << "--- Test Attack ---" << std::endl;
    ScavTrap.attack("Target1");
    ScavTrap.takeDamage(5);

	std::cout << std::endl << "--- Test Repair ---" << std::endl;
    ScavTrap.beRepaired(5);

	std::cout << std::endl << "--- Test Guardgate ---" << std::endl;
    ScavTrap.guardGate();
    ScavTrap.attack("Target2");

    return 0;
}