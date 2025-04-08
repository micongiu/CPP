#include "include/DiamondTrap.hpp"

int main() {
    std::cout << std::endl << "--- Test DiamondTrap ---" << std::endl;
    DiamondTrap DiamondTrap("Diamond");

    std::cout << std::endl << "--- Test WhoAmI ---" << std::endl;
    DiamondTrap.whoAmI();

    std::cout << std::endl << "--- Test Attack ---" << std::endl;
    DiamondTrap.attack("target");

    std::cout << std::endl << "--- Test DiamondTrap parameters ---" << std::endl;
    std::cout << "Hit Points: " << DiamondTrap.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << DiamondTrap.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << DiamondTrap.getAttackDamage() << std::endl;

    std::cout << std::endl << "--- Test Special abilities ---" << std::endl;
    DiamondTrap.highFivesGuys();
    DiamondTrap.guardGate();

    std::cout << std::endl << "--- Test Destruction ---" << std::endl;

    return 0;
}