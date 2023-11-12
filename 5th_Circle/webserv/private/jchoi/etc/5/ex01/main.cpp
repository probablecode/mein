#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
	std::cout << std::endl << std::endl;
	Bureaucrat c("jchoi", 1);
	std::cout << c;
	Form f42("form42", 42, 42);
	std::cout << f42;
	
	std::cout << std::endl;
	f42.beSigned(c);
	std::cout << f42;


	std::cout << std::endl << std::endl;
	Bureaucrat d("Norminette", 77);
	std::cout << d;
	Form f76("form76", 76);
	std::cout << f76;
	
	std::cout << std::endl;
	f76.beSigned(d);
	std::cout << f76;
	
	std::cout << std::endl << std::endl;
	return (0);
}
