#include "../include/HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
};

HumanB::~HumanB()
{
};

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->_weapon = &newWeapon;
}

void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is unarmed" << std::endl;
}

