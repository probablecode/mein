#include "Bureaucrat.hpp"
int main( void )
{
	Bureaucrat a;
	std::cout << a;
	try {a.decrement();}catch (std::exception &e){std::cout << e.what();}
	try {a.increment();}catch (std::exception &e){std::cout << e.what();}
	std::cout << a;
	std::cout << std::endl << std::endl;

	Bureaucrat b("Norminette", -1);
	try {b.decrement();}catch (std::exception &e){std::cout << e.what();}
	try {b.increment();}catch (std::exception &e){std::cout << e.what();}
	std::cout << b;
	std::cout << std::endl << std::endl;

	Bureaucrat c("jchoi", 1);
	try {c.increment();}catch (std::exception &e){std::cout << e.what();}
	try {c.decrement();}catch (std::exception &e){std::cout << e.what();}
	std::cout << c;
	std::cout << std::endl << std::endl;

	Bureaucrat d("gogo", 151);
	try {d.increment();}catch (std::exception &e){std::cout << e.what();}
	try {d.decrement();}catch (std::exception &e){std::cout << e.what();}
	std::cout << d;
	std::cout << std::endl << std::endl;

	return (0);
}
