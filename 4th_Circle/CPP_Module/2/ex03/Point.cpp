#include "Point.hpp"
Point::Point() : x(), y() {}
Point::Point(const float xFloat, const float yFloat) : x(xFloat), y(yFloat) {}
Point::Point(const Point &point) : x(point.getX()), y(point.getY()) {} 
Point::~Point() {}
Point	&Point::operator=(const Point &point)
{
	(void)point;
	return (*this);
}
const Fixed	Point::getX() const {return (x);}
const Fixed	Point::getY() const {return (y);}
