#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string _weaponName;

	public:
		Weapon( std::string);
		~Weapon();

		const std::string& getType() const;
		void setType( std::string newWeapon);
};

#endif
