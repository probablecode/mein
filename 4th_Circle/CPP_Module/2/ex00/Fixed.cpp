#include "Fixed.hpp"
Fixed::Fixed()
{
	fixedNum = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	fixedNum = fixed.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (fixedNum);
}

void	Fixed::setRawBits( int const raw )
{
	fixedNum = raw;
}
