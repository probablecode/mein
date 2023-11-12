#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char	*NoAccordingFormException::what() const throw()
{
	const char	*ret = "[Exception Occurs] : There's no according Form\n";
	return (ret);
}

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &copy) {(void)copy;}
Intern	&Intern::operator=(const Intern &ref) {(void)ref;return (*this);}

Form	*Intern::makeForm(std::string formName, std::string target)
{
	static std::string	formNames[3]
		= {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form*	ret = nullptr;
	Form*	forms[3];
	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);
	
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (formNames[i] == formName)
			{
				ret = forms[i];
				forms[i] = nullptr;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
		if (!ret)
			throw eNo;
	}
	catch	(std::exception &e)
	{
		std::cout << e.what();
	}
	return (ret);
}
