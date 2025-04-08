#include "include/ClapTrap.hpp"

int main()
{
    ClapTrap ClapTrap1("ClapOne");
    ClapTrap ClapTrap2("ClapTwo");

    std::cout << std::endl << "--- Test Attack ---" << std::endl;
    ClapTrap1.attack("ClapTwo");
    ClapTrap2.takeDamage(ClapTrap1.getAttackDamage());

    std::cout << std::endl << "--- Test Repair ---" << std::endl;
    ClapTrap2.beRepaired(5);

    std::cout << std::endl << "--- Test Energy Consumption ---" << std::endl;
    for (int i = 0; i < 11; i++) 
        ClapTrap1.attack("ClapTwo");

    std::cout << std::endl << "--- Test Repair with No Energy ---" << std::endl;
    ClapTrap1.beRepaired(3);

    std::cout << std::endl << "--- Test Destruction ---" << std::endl;
    ClapTrap1.takeDamage(20);
    ClapTrap1.attack("ClapTwo");
    ClapTrap1.beRepaired(10);

    return 0;
}