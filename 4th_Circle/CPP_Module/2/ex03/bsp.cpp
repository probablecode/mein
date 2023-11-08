#include "Point.hpp"

static Fixed det(Point const c1, Point const c2, Point const point)
{
	Fixed	x1(c1.getX());
	Fixed	y1(c1.getY());
	Fixed	x2(c2.getX());
	Fixed	y2(c2.getY());
	Fixed	pX(point.getX());
	Fixed	pY(point.getY());

	return ((x2 - x1) * pY - (y2 - y1) * pX + x1 * y2 - x2 * y1);
}

static bool	sp(Point const c1, Point const c2, Point const cmp, Point const point)
{
	Fixed zero;

	return (zero < det(c1, c2, cmp) * det(c1, c2, point));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (sp(a, b, c, point) && sp(b, c, a, point) && sp(c, a, b, point));
}
