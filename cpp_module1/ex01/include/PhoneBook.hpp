#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"

# define RED	"\033[91m"
# define GREEN	"\033[92m"
# define BLUE	"\033[94m"
# define WHITE	"\033[0m"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		indexCount;
	public:
		PhoneBook();
		~PhoneBook();
	
		void addFirstName(int index);
		void addLastName(int index);
		void addNickname(int index);
		void addPhoneNumber(int index);
		void addDarkestSecret(int index);
		void add();

		void search(int index);
};

#endif
