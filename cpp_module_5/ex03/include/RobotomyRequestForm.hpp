#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
		~RobotomyRequestForm();

		void useForm() const;
};

#endif
