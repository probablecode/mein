#ifndef	FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
	private	:
		int	fixedNum;
		static const int	fracBit = 8;
	public	:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int);
		Fixed(const float);
		Fixed	&operator=(const Fixed &fixed);
		~Fixed();

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);
#endif
