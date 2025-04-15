#include "../include/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA: " << this->_name << " is create" << std::endl;
};

HumanA::~HumanA()
{
	std::cout << "HumanA: " << this->_name << " is dead" << std::endl;
};

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
};
