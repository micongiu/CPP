#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( const DiamondTrap& src );
		DiamondTrap& operator=( const DiamondTrap& src );
		~DiamondTrap();

		void whoAmI(void);
		using ScavTrap::attack;
};

#endif
