#include "../include/Zombie.hpp"

Zombie::Zombie( void ) : _name("Foo")
{
	std::cout << "Zombie: " << this->_name << " is create" << std::endl;
};

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "Zombie: " << this->_name << " is create" << std::endl;
};

Zombie::~Zombie( void )
{
	std::cout << "Zombie: " << this->_name << " is dead" << std::endl;
};

void Zombie::setName( std::string name )
{
	this->_name = name;
};

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
