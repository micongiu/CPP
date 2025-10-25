#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T 		*array;
		size_t	len;

	public:
		Array();
		Array( unsigned int n );
		Array(const Array &src);
		Array&	operator=(const Array &src);
		~Array();

		T&		operator[](size_t idx) const;

		size_t size() const;
};

#include "Array.tpp"

#endif