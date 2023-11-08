#include "Span.hpp"
int main()
{
	Span small = Span(5);
	try {std::cout << small.shortestSpan() << std::endl;}
	catch (std::exception &e){std::cout << e.what();}
	small.addNumber(1);
	try {std::cout << small.longestSpan() << std::endl;}
	catch (std::exception &e){std::cout << e.what();}
	small.addNumber(43);
	try {std::cout << small.shortestSpan() << std::endl;
		std::cout << small.longestSpan() << std::endl;}
	catch (std::exception &e){std::cout << e.what();}


	std::vector<int>	v;
	for (int i = 1; i < 10; i++)
		v.push_back(i*i);
	Span sp = Span(10);
	sp.rangeAdd(v.begin(), v.end());
	
	sp.addNumber(90);
	try
	{
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
