#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
class RobotomyRequestForm : public Form
{
	private	:
		std::string	target;
	public	:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string pName);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};
#endif
