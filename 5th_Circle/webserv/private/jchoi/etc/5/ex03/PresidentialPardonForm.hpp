#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public Form
{
	private	:
		std::string	target;
	public	:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string pName);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};
#endif
