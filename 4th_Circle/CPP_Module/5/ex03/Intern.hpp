#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class NoAccordingFormException : public std::exception
{
	public	:
		const char	*what() const throw();
};
class Intern
{
	public	:
		NoAccordingFormException eNo;
		
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &ref);

		Form	*makeForm(std::string form, std::string target);
};
#endif
