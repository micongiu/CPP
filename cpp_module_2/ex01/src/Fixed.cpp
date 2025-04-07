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

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = src << Fixed::_fractionalBits;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = static_cast<int>(roundf(src * (1 << _fractionalBits)));
}

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


float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixed) / (1 << Fixed::_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed >> Fixed::_fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}
