#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <iostream>
# include <stdint.h>

typedef struct s_data
{
	std::string	name;
	std::string	surName;
	int			age;
} Data;

class Serialization
{
	private:
	// Which will not be initializable by the user in any way. So I declare them as private
		Serialization();
		Serialization(const Serialization& src);
		
	public:
		~Serialization();
		Serialization& operator=(const Serialization& src);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif