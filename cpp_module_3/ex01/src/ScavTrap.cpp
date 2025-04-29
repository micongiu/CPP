#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "-ScavTrap- " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "-ScavTrap- " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	*this = src;
	std::cout << "-ScavTrap- " << this->_name << " created as a copy of " << src.getName() << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& src )
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
};

ScavTrap::~ScavTrap()
{
	std::cout << "-ScavTrap- " << this->_name << " destroyed" << std::endl;
};

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy and can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void ScavTrap::guardGate()
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't enter Gatekeeper!" << std::endl;
		return;
	}
	
	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode!" << std::endl;
};