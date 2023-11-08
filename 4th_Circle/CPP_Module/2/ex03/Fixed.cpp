#include "Fixed.hpp"
Fixed::Fixed()
{
	fixedNum = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	fixedNum = fixed.getRawBits();
}

Fixed::Fixed(const int integer)
{
	setRawBits(integer << 8);
}

Fixed::Fixed(const float floating)
{
	float	tmp = floating;
	
	for (int i = 0; i < 8; i++)
		tmp *= 2.0F;
	tmp = roundf(tmp);
	setRawBits(tmp);
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
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

int	Fixed::toInt( void ) const
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

bool	Fixed::operator>(const Fixed &f)
{
	return (this->getRawBits() > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f)
{
	return (this->getRawBits() < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f)
{
	return (this->getRawBits() >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f)
{
	return (this->getRawBits() <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f)
{
	return (this->getRawBits() == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f)
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed	Fixed::operator+(const Fixed&f)
{
	Fixed	temp;
	temp.setRawBits(this->getRawBits() + f.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-(const Fixed&f)
{
	Fixed	temp;
	temp.setRawBits(this->getRawBits() - f.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*(const Fixed&f)
{
	Fixed	temp;

	long raw1 = this->getRawBits();
	long raw2 = f.getRawBits();
	temp.setRawBits((int)((raw1 * raw2) >> 8));
	return (temp);
}

Fixed	Fixed::operator/(const Fixed&f)
{
	Fixed	temp;
	
	long raw1 = this->getRawBits();
	long raw2 = f.getRawBits();
	temp.setRawBits((int)(raw1 / raw2));
	return (temp);
}

Fixed	&Fixed::operator++()
{
	int	raw = getRawBits();
	setRawBits(++raw);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	int	raw = getRawBits();
	setRawBits(++raw);
	return (temp);
}
Fixed	&Fixed::operator--()
{
	int	raw = getRawBits();
	setRawBits(--raw);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	int	raw = getRawBits();
	setRawBits(--raw);
	return (temp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f1 : f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	Fixed	t1(f1);
	Fixed	t2(f2);
	return ((t1 < t2) ? f1 : f2);
}
Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 < f2) ? f2 : f1);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{	
	Fixed	t1(f1);
	Fixed	t2(f2);
	return ((t1 < t2) ? f2 : f1);
}
