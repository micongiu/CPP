#include "../include/Harl.hpp"

Harl::Harl()
{
};
Harl::~Harl()
{
};

void Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};

void Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << " cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
};

void Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

void Harl::complain( std::string level )
{
	void (Harl::*actionsPtr[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	int level_int;

	if (level == "DEBUG")
        level_int = 0;
    else if (level == "INFO")
        level_int = 1;
    else if (level == "WARNING")
        level_int = 2;
    else if (level == "ERROR")
        level_int = 3;
    else 
	{
        level_int = 4;
	}

	switch (level_int)
	{
		case 0:
			(this->*actionsPtr[0])();
			break;
		case 1:
			(this->*actionsPtr[1])();
			break;
		case 2:
			(this->*actionsPtr[2])();
			break;
		case 3:
			(this->*actionsPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
};
