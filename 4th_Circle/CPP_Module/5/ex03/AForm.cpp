#include "AForm.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(LOWEST), gradeToExecute(HIGHEST) {
	std::cout << "Form's default constructor is called\n";
}

Form::Form(const std::string pName, int pGradeToSign, int pGradeToExecute)
	: name(pName), isSigned(false), gradeToSign(pGradeToSign), gradeToExecute(pGradeToExecute)
{
	try
	{
		std::cout << "gradeToSign vailidity check ...  ";
		if (gradeToSign < HIGHEST)
			throw eHigh;
		else if (LOWEST < gradeToSign)
			throw eLow;
		std::cout << "\ngradeToExecute vailidity check ...  ";
		if (gradeToExecute < HIGHEST)
			throw eHigh;
		else if (LOWEST < gradeToExecute)
			throw eLow;	
		std::cout << "\nForm " << name <<"\'s constructor is successfully called\n";
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
}

Form::Form(const Form &ref) : name(ref.name), isSigned(ref.isSigned),
	gradeToSign(ref.gradeToSign), gradeToExecute(ref.gradeToExecute) {
	std::cout << "Form " << name <<"\'s copy constructor is called\n";
}

Form::~Form() {
	std::cout << "Form " << name <<"\'s destructor is called\n";
}

Form	&Form::operator=(const Form &ref)
{
	(void)ref;
	std::cout << "this function will never be called, if you see this sentence, something is seriously wrong\n";
	return (*this);
}

void	Form::beSigned(const Bureaucrat &ref)
{
	if (isSigned)
		std::cout << "this Form is already signed\n";
	else
	{
		try
		{
			if (ref.getGrade() <= gradeToSign)
				isSigned = true;
			ref.signForm(name, isSigned);
			if (!isSigned)
				throw eLow;
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
		}
	}
}


const std::string	Form::getName() const {return (name);}
int	Form::getGradeToSign() const {return (gradeToSign);}
int	Form::getGradeToExecute() const {return (gradeToExecute);}
bool	Form::getIsSigned() const {return (isSigned);}

std::ostream	&operator<<(std::ostream &os, const Form &ref)
{
	if (ref.getGradeToSign() < HIGHEST || LOWEST < ref.getGradeToSign()
			|| ref.getGradeToExecute() < HIGHEST || LOWEST < ref.getGradeToExecute())
		os << "[stdout print refused] : This Form data is corrupted (grade out of range)\n"; 
	else
	{
		os << "[Form information]\n//=================="\
			<< "\n[Name] : " << ref.getName()\
			<< "\n[IsSigned] : " << std::boolalpha << ref.getIsSigned()\
			<< "\n[GradeToSign] : " << ref.getGradeToSign()\
			<< "\n[GradeToExecute] : " << ref.getGradeToExecute()\
			<< "\n//===================\n";
	}
	return (os);
}

const char	*FormIsUnsigned::what() const throw()
{
	static const char	*ret = "[Exception occur] : Form is unsigned\n";
	return (ret);
}
