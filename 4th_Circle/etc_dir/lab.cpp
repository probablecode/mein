#include <iostream>
int	main()
{
	int x = 4;
	
//	int	&refpost = x++;
	int	&refpre = ++x;
	
//	int	*ptrpost = &(x++);
	int	*ptrpre = &(++x);
	std::cout << x << std::endl;
//	std::cout << refpost << std::endl;
	std::cout << refpre << std::endl;
//	std::cout << ptrpost << *ptrpost << std::endl;
	std::cout << ptrpre << *ptrpre << std::endl;
	return (0);
}
