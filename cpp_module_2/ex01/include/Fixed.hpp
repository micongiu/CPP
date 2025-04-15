#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _fixed;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed( const Fixed& src );
		Fixed( const int src );
		Fixed( const float src );
		Fixed& operator=( const Fixed& src );
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, const Fixed& src );

#endif
