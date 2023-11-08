#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm : public Form
{
	private	:
		std::string	target;
	public	:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string pName);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm();
		void	execute(Bureaucrat const &executor) const;
};
#endif
