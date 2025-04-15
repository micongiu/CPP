#include "../include/Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is create" << std::endl;
};
Harl::~Harl()
{
	std::cout << "Harl is dead" << std::endl;
};

void Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
};

void Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
};

void Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
};

void Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
};

void Harl::complain( std::string level )
{
	int level_int;

	level_int = 0;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	while (level_int < 4 && levels[level_int].compare(level))
		level_int++;

	switch (level_int)
	{
		case 0:
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 1:
			this->_info();
			this->_warning();
			this->_error();
			break ;
		case 2:
			this->_warning();
			this->_error();
			break ;
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
};
