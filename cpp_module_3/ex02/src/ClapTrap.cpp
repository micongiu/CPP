#include "../include/ClapTrap.hpp"

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

ClapTrap& ClapTrap::operator=( const ClapTrap& src )
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	return (*this);
};

ClapTrap::~ClapTrap()
{
	std::cout << "-ClapTrap- " << this->_name << " destroyed" << std::endl;
};

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't take Damage!" << std::endl;
		return;
	}
	if (amount >= (unsigned int)this->_hitPoints)
	{
		this->_hitPoints = 0;
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

void ClapTrap::beRepaired(unsigned int amount)
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
