#include "../include/Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << this->getName() << " created" << "\n";
}

Character::Character( const std::string &name )
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << this->getName() << " created" << "\n";
}

Character::Character(const Character& src)
{
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character " << this->getName() << " created as a copy of Character" << "\n";
}

Character& Character::operator=( const Character& src )
{
	std::cout << "Character " << this->getName() << " -assignation operator- called" << "\n";
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		this->_name = src.getName(); 
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << this->getName() << " destroyed" << "\n";
}

std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Character " << this->_name << " equip" << m->getType() << "\n";
			return;
		}
	}
	std::cout << "Character " << this->_name << " Inventory is full" << "\n";
}

void Character::unequip(int idx)
{
	if (this->_inventory[idx])
	{
		std::cout << this->_name << "unequip" << this->_inventory[idx]->getType() << "\n";
		this->_inventory[idx] = NULL;
		return;
	}
	std::cout << "Character " << this->_name << "Inventory is full" << "\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "Character " << "Invalid inventory slot" << "\n";
		return;
	}
	this->_inventory[idx]->use(target);
}

