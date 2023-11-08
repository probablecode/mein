#include "Fixed.hpp"
Fixed::Fixed()
{
	fixedNum = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	fixedNum = fixed.getRawBits();
	std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int integer)
{
	setRawBits(integer << 8);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floating)
{
	float	tmp = floating;
	
	for (int i = 0; i < 8; i++)
		tmp *= 2.0F;
	tmp = roundf(tmp);
	setRawBits(tmp);
	std::cout << "Float constructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits( void ) const
{
	return (fixedNum);
}

void	Fixed::setRawBits( int const raw )
{
	fixedNum = raw;
}

int		Fixed::toInt( void ) const
{
	int raw = getRawBits();

	if (raw == 1 << 31)
		return (-(1 << 23));
	else if (raw < 0)
		return (-((~raw + 1) >> 8));
	else
		return (raw >> 8);
}

float	Fixed::toFloat( void ) const
{
	float	result = 0;
	int	raw = getRawBits();
	int	sign = (0 < raw) - (raw < 0);
	unsigned int	quantity;

	if (sign)
	{
		quantity = (0 < sign) * raw + (sign < 0) * ((unsigned int)(~raw) + 1);
		unsigned int bit = 1 << 31;
		while (!(bit & quantity))
			bit >>= 1;
		for (int i = 0; i < 24 && 0 < bit; i++)
		{
			result *= 2.0F;
			if (bit & quantity)
				result += 1.0F;
			bit >>= 1;
		}
	}
	return ((result * sign) / 256.0F);
}
