#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
Base	*generate(void)
{
	Base	*ret;

	srand((unsigned int)time(NULL));
	int choice = rand() % 3;
	std::cout << "[" << choice << "]\n";
	switch (choice)
	{
		case 0 :
			ret = new A;
			break;
		case 1 :
			ret = new B;
			break;
		case 2 :
			ret = new C; 
			break;
	}
	return (ret);
}

void	identify(Base *p)
{
	std::cout << "let me guess by pointer...\n";
	if (dynamic_cast<A*>(p))
		std::cout << "It's A!\n";
	if (dynamic_cast<B*>(p))
		std::cout << "It's B!\n";
	if (dynamic_cast<C*>(p))
		std::cout << "It's C!\n";

}


void	identify(Base &p)
{
	std::cout << "let me guess by reference...\n";
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "Yes, It's A!\n";
		(void)a;
	}
	catch (std::exception &e) {std::cout << "No, It's not A!\n";}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "Yes, It's B!\n";
		(void)b;
	}
	catch (std::exception &e) {std::cout << "No, It's not B!\n";}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "Yes, It's C!\n";
		(void)c;
	}
	catch (std::exception &e) {std::cout << "No, It's not C!\n";}

}

			

int	main()
{
	Base	*randomBase = ::generate();
	::identify(randomBase);
	::identify(*randomBase);
	
	delete randomBase;
	return (0);
}
