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
		Fixed& operator=( const Fixed& src );
		Fixed( const int src );
		Fixed( const float src );
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator > ( const Fixed& src ) const;
		bool operator < ( const Fixed& src ) const;
		bool operator >= ( const Fixed& src ) const;
		bool operator <= ( const Fixed& src ) const;
		bool operator == ( const Fixed& src ) const;
		bool operator != ( const Fixed& src ) const;

		Fixed operator + ( const Fixed& src ) const;
		Fixed operator - ( const Fixed& src ) const;
		Fixed operator * ( const Fixed& src ) const;
		Fixed operator / ( const Fixed& src ) const;

		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++( int );
		Fixed operator--( int );

		static Fixed& min( Fixed& a, Fixed& b );
		static const Fixed& min( const Fixed& a, const Fixed& b );
		static Fixed& max( Fixed& a, Fixed& b );
		static const Fixed& max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<( std::ostream& os, const Fixed& src );

#endif
