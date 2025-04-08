#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "Default";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;

	std::cout << "-DiamondTrap- " << this->_name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap("Default_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;

	std::cout << "-DiamondTrap- " << this->_name << " created" << std::endl;
};

DiamondTrap::DiamondTrap( const DiamondTrap& src ) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << "-DiamondTrap- " << this->_name << " created as a copy of " << src.getName() << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& src )
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "-DiamondTrap- " << this->_name << " destroyed." << std::endl;
};


void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " " << this->ClapTrap::getName() << std::endl;
};
