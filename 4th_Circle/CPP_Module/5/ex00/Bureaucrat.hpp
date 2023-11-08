#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#define HIGHEST 1
#define LOWEST	150

class GradeTooHighException : public std::exception
{
	public	:
		const char	*what() const throw();
};

class GradeTooLowException : public std::exception
{
	public	:
		const char	*what() const throw();
};

class Bureaucrat
{
	private	:
		const std::string	name;
		int	grade;
		GradeTooHighException eHigh;
		GradeTooLowException eLow;
	public	:
		Bureaucrat();
		Bureaucrat(const std::string pName, int pGrade = 150);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &ref);
		~Bureaucrat();

		const std::string	getName() const ;
		int	getGrade() const ;
		void	increment();
		void	decrement();
};
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref);
#endif
