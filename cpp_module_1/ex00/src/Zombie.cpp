#include "../include/Zombie.hpp"

Zombie::Zombie( void ) : _name("Foo")
{
};

Zombie::~Zombie( void )
{
	std::cout << "Zombie: " << this->_name << " is dead" << std::endl;
};

Zombie::Zombie( std::string name ) : _name(name)
{
};

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
