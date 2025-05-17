#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << "\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << this->getName() << " assignation operator called" << "\n";
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << "\n";
}

void ShrubberyCreationForm::useForm() const
{
	std::ofstream file;
	std::string filename = this->_target + "_shrubbery";

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << "\n";
		return ;
	}

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\" << "\n";
	
	file.close();
}
