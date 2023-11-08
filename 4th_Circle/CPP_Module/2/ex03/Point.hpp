#ifndef	POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
	private	:
		Fixed const	x;
		Fixed const	y;
	public	:
		Point();
		Point(const float xFloat, const float yFloat);
		Point(const Point &point);
		Point	&operator=(const Point &point);
		~Point();
		const Fixed	getX() const;
		const Fixed	getY() const;
};
#endif
