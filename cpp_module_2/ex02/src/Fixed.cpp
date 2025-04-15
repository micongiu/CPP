#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	
};

Fixed::Fixed( const Fixed& src )
{
	*this = src;
};

Fixed::Fixed(const int src)
{
	this->_fixed = src << Fixed::_fractionalBits;
}

Fixed::Fixed(const float src)
{
	this->_fixed = static_cast<int>(roundf(src * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=( const Fixed& src )
{
	if (this != &src)
		this->_fixed = src.getRawBits();
	return (*this);
};

Fixed::~Fixed()
{
};

int Fixed::getRawBits( void ) const
{
	return (this->_fixed);
};

void Fixed::setRawBits( int const raw )
{
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

bool Fixed::operator > (const Fixed& src) const
{
	return(this->_fixed > src.getRawBits());
};

bool Fixed::operator < (const Fixed& src) const
{
	return(this->_fixed < src.getRawBits());
};

bool Fixed::operator >= (const Fixed& src) const
{
	return(this->_fixed >= src.getRawBits());

};

bool Fixed::operator <= (const Fixed& src) const
{
	return(this->_fixed <= src.getRawBits());

};

bool Fixed::operator == (const Fixed& src) const
{
	return(this->_fixed == src.getRawBits());

};

bool Fixed::operator != (const Fixed& src) const
{
	return(this->_fixed != src.getRawBits());
};

Fixed Fixed::operator+(const Fixed& src) const
{
	Fixed result;

	result.setRawBits(this->_fixed + src.getRawBits());
	return (result);
};

Fixed Fixed::operator-(const Fixed& src) const
{
	Fixed result;
	
	result.setRawBits(this->_fixed - src.getRawBits());
	return (result);
};

Fixed Fixed::operator*(const Fixed& src) const
{
	Fixed result;
	
	result.setRawBits((this->_fixed * src.getRawBits() >> Fixed::_fractionalBits));
	return (result);
};

Fixed Fixed::operator/(const Fixed& src) const
{
	Fixed result;

	result.setRawBits((this->_fixed << Fixed::_fractionalBits) / src.getRawBits());
	return (result);
};

Fixed& Fixed::operator++()
{
	this->_fixed++;
	return(*this);
};

Fixed& Fixed::operator--()
{
	this->_fixed--;
	return(*this);
};

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	operator++();
	return tmp;
};

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	
	operator--();
	return tmp;
};

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return(a < b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	return (a > b ? a : b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	return (a < b ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}
