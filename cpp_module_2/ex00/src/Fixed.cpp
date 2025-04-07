#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

};

Fixed& Fixed::operator=( const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixed = src.getRawBits();
	return (*this);

};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

};

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function " << std::endl;
	return (this->_fixed);

};

void Fixed::setRawBits( int const raw )
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = raw;
};
