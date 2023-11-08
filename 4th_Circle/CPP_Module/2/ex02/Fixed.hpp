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

		bool	operator>(const Fixed &f);
		bool	operator<(const Fixed &f);
		bool	operator>=(const Fixed &f);
		bool	operator<=(const Fixed &f);
		bool	operator==(const Fixed &f);
		bool	operator!=(const Fixed &f);

		Fixed	operator+(const Fixed&f);
		Fixed	operator-(const Fixed&f);
		Fixed	operator*(const Fixed&f);
		Fixed	operator/(const Fixed&f);

		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};
std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);
#endif
