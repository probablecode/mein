#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main( void )
{

	std::cout << std::endl << std::endl;
	Bureaucrat c("jchoi", 1);
	std::cout << c;
	ShrubberyCreationForm f1("Jchoi[sh]");
	std::cout << f1;
	std::cout << std::endl;
	f1.beSigned(c);
	std::cout << f1;
	c.executeForm(f1);

	RobotomyRequestForm f2("Jchoi[Ro]");
	std::cout << f2;
	std::cout << std::endl;
	f2.beSigned(c);
	std::cout << f2;
	c.executeForm(f2);

	PresidentialPardonForm f3("Jchoi[Pr]");
	std::cout << f3;
	std::cout << std::endl;
	f3.beSigned(c);
	std::cout << f3;
	c.executeForm(f3);

	




	std::cout << "\n\n\n\n";
	Bureaucrat d("norminette", 50);
	std::cout << d;
	ShrubberyCreationForm g1("Norminette[sh]");
	std::cout << g1;
	std::cout << std::endl;
	g1.beSigned(d);
	std::cout << g1;
	d.executeForm(g1);

	RobotomyRequestForm g2("Norminette[Ro]");
	std::cout << g2;
	std::cout << std::endl;
	g2.beSigned(d);
	std::cout << g2;
	d.executeForm(g2);

	PresidentialPardonForm g3("Norminette[Pr]");
	std::cout << g3;
	std::cout << std::endl;
	g3.beSigned(d);
	std::cout << g3;
	d.executeForm(g3);

	return (0);
}
