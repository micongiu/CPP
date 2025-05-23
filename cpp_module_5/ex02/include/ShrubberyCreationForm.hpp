#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& src );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& src );
		~ShrubberyCreationForm();

		void useForm() const;
};

#endif