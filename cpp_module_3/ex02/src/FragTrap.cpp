#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "-FragTrap- " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "-FragTrap- " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	*this = src;
	std::cout << "-FragTrap- " << this->_name << " created as a copy of " << src.getName() << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src )
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
};

FragTrap::~FragTrap()
{
	std::cout << "-FragTrap- " << this->_name << " destroyed" << std::endl;
};

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " is out of energy and can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void FragTrap::highFivesGuys()
{
	if (this->_hitPoints < 1)
	{
		std::cout << "FragTrap " << this->_name << " is dead and can't give high Fives Guys!" << std::endl;
		return;
	}
	
	std::cout << "FragTrap " << this->_name << " says 'High Five Guys!'" << std::endl;
};