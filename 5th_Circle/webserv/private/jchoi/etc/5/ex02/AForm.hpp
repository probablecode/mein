#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
class FormIsUnsigned : public std::exception
{
	public	:
		const char	*what() const throw();
};

class Form
{
	private	:
		const std::string	name;
		bool	isSigned;
		const int	gradeToSign;
		const int	gradeToExecute;

	public	:
		GradeTooHighException eHigh;
		GradeTooLowException eLow;
		FormIsUnsigned	eUnsigned;

		Form();
		Form(const std::string pName, const int pGradeToSign = 150, const int pGradeToExecute = 1);
		Form(const Form &copy);
		Form	&operator=(const Form &ref);
		virtual ~Form();

		void	beSigned(const Bureaucrat &ref);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		const std::string	getName() const ;
		int	getGradeToSign() const ;
		int	getGradeToExecute() const ;
		bool	getIsSigned() const ;
};
std::ostream	&operator<<(std::ostream &os, const Form &ref);
#endif
