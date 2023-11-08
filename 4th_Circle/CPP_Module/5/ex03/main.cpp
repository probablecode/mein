#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main( void )
{
	Intern intern;
	Form	*rrf;
	rrf = intern.makeForm("hoho", "Bendor");
	delete rrf;


	Bureaucrat jchoi("jchoi", 1);
	rrf = intern.makeForm("shrubbery creation", "Bendor");
//	rrf = intern.makeForm("robotomy request", "Bendor");
//	rrf = intern.makeForm("presidential pardon", "Bendor");

	rrf->beSigned(jchoi);
	jchoi.executeForm(*rrf);
	delete rrf;
	return (0);
}
