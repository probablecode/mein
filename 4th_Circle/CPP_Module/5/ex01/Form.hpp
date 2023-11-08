#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Form
{
	private	:
		const std::string	name;
		bool	isSigned;
		const int	gradeToSign;
		const int	gradeToExecute;

		GradeTooHighException eHigh;
		GradeTooLowException eLow;
	public	:
		Form();
		Form(const std::string pName, const int pGradeToSign = 150, const int pGradeToExecute = 1);
		Form(const Form &copy);
		Form	&operator=(const Form &ref);
		~Form();

		void	beSigned(const Bureaucrat &ref);
		
		const std::string	getName() const ;
		int	getGradeToSign() const ;
		int	getGradeToExecute() const ;
		bool	getIsSigned() const ;

};
std::ostream	&operator<<(std::ostream &os, const Form &ref);
#endif
