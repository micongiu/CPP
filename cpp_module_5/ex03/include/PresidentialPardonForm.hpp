#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm( std::string target );
        PresidentialPardonForm( const PresidentialPardonForm& src );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& src );
        ~PresidentialPardonForm();

        void useForm() const;
};

#endif