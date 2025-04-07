#include "include/Fixed.hpp"

int main()
{
    ClapTrap clap1("ClapOne");
    ClapTrap clap2("ClapTwo");

    std::cout << std::endl << "--- Test Attack ---" << std::endl;
    clap1.attack("ClapTwo");
    clap2.takeDamage(clap1.getAttackDamage());

    std::cout << std::endl << "--- Test Repair ---" << std::endl;
    clap2.beRepaired(5);

    std::cout << std::endl << "--- Test Energy Consumption ---" << std::endl;
    for (int i = 0; i < 11; i++) 
        clap1.attack("ClapTwo");

    std::cout << std::endl << "--- Test Repair with No Energy ---" << std::endl;
    clap1.beRepaired(3);

    std::cout << std::endl << "--- Test Destruction ---" << std::endl;
    clap1.takeDamage(20);
    clap1.attack("ClapTwo");
    clap1.beRepaired(10);

    return 0;
}