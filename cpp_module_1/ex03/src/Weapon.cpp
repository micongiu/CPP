#include "../include/Weapon.hpp"

Weapon::Weapon( std::string name) : _weaponName(name)
{
};
Weapon::~Weapon()
{
};

const std::string& Weapon::getType() const
{
	return this->_weaponName;
};

void Weapon::setType( std::string newWeapon)
{
	this->_weaponName = newWeapon;
};
