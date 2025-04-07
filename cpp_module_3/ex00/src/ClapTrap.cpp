#include "../include/Claptrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "-ClapTrap- " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "-ClapTrap- " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "-ClapTrap- " << this->_name << " created as a copy of " << src.getName() << std::endl;
}

Claptrap& Claptrap::operator=( const Claptrap& src )
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
};

Claptrap::~Claptrap()
{
	std::cout << "-ClapTrap- " << this->_name << " destroyed" << std::endl;
};


void Claptrap::attack(const std::string& target)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
};

void Claptrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't take Damage!" << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "-ClapTrap- " << this->_name << " took " << amount 
			<< " points of damage!" << std::endl;
	}
};	

void Claptrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't be Repaired!" << std::endl;
		return;
	}
	if (this->_hitPoints >= 10)
	{
		std::cout << "ClapTrap " << this->_name << " is full" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't be repaired!" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_energyPoints += amount;
	std::cout << "-ClapTrap- " << this->_name << " repairs itself by " 
              << amount << " hit points! Current hit points: " 
              << this->_hitPoints << std::endl;
};
