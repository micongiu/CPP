#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap( const FragTrap& src );
		FragTrap& operator=( const FragTrap& src );
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys();
};

#endif
