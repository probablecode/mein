#include "Point.hpp"
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point const	a1(1.1f, 2.1f);
	Point const	b1(5.5f, 8.4f);
	Point const	c1(10.7f, 0.3f);
	Point const	point1(4.2f, 4.2f);

	if (bsp(a1, b1, c1, point1))
		std::cout << "true\n";
	else
		std::cout << "false\n";
	
	Point const	a2(1.25f, 2.5f);
	Point const	b2(1.25f, 8.5f);
	Point const	c2(10.25f, 2.5f);
	Point const	point2(7.25f, 4.5f);

	if (bsp(a2, b2, c2, point2))
		std::cout << "true\n";
	else
		std::cout << "false\n";



	return 0;
}
