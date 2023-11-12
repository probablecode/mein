#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(LOWEST) {
	std::cout << "Bureaucrat's default constructor is called\n";
}

Bureaucrat::Bureaucrat(const std::string pName, int pGrade) : name(pName), grade(pGrade)
{
	try
	{
		if (grade < HIGHEST)
			throw eHigh;
		else if (LOWEST < grade)
			throw eLow;
		std::cout << "Bureaucrat " << name <<"\'s constructor is called\n";
	}
	catch (std::exception &e){
		std::cout << e.what();
		std::cout << "you should not use this Bureaucrat\n";
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade) {
	std::cout << "Bureaucrat " << name <<"\'s copy constructor is called\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << name <<"\'s destructor is called\n";
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &ref)
{
	(void)ref;
	std::cout << "this function will never be called, if you see this sentence, something is seriously wrong\n";
	return (*this);
}

void	Bureaucrat::increment()
{
	if (grade <= HIGHEST)
		throw eHigh;
	else if (LOWEST < grade)
		throw eLow;
	std::cout << "increment of bureaucrat " << name << "'s grade is succesfully done";
	std::cout << " [from " << grade--;
	std::cout << " to " << grade << "]\n";
}

void	Bureaucrat::decrement()
{
	if (grade < HIGHEST)
		throw eHigh;
	else if (LOWEST <= grade)
		throw eLow;
	std::cout << "decrement of bureaucrat " << name << "'s grade is succesfully done";
	std::cout << " [from " << grade++;
	std::cout << " to " << grade << "]\n";
}

void	Bureaucrat::signForm(const std::string formName, bool formIsSigned) const
{
	if (formIsSigned)
		std::cout << "Bureaucrat " << name << " signed " << formName << std::endl;
	else
		std::cout << "Bureaucrat " << name << " couldn't sign " << formName <<" because ";
}

const std::string	Bureaucrat::getName() const {return (name);}
int	Bureaucrat::getGrade() const {return (grade);}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &ref)
{
	if (ref.getGrade() < HIGHEST || LOWEST < ref.getGrade())
		os << "[stdout print refused] : This Bureaucrat data is corrupted (grade out of range)\n"; 
	else
		os << ref.getName() << ", bereaucrat grade " << ref.getGrade() << ".\n";
	return (os);
}

const char	*GradeTooHighException::what() const throw()
{
	static const char	*ret = "[Exception occur] : Grade too high\n";
	return (ret);
}
const char	*GradeTooLowException::what() const throw()
{
	static const char	*ret = "[Exception occur] : Grade too low\n";
	return (ret);
}

void	Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << name << " excuted " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << name << " failed to execute " << form.getName()\
			<< " because " << e.what();
	}
}
