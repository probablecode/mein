#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
 : Form("Presidential", 25, 5), target("void")
{
	std::cout << "PresidentialPardonForm's default constructor is called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string pTarget)
 : Form("Presidential", 25, 5), target(pTarget)
{
		std::cout << "\nPresidentialPardonForm " << getName()\
			<<"\'s constructor is successfully called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
 : Form(ref), target(ref.target)
{
	std::cout << "PresidentialPardonForm " << getName()\
		<< "\'s copy constructor is called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm " << getName()\
		<<"\'s destructor is called\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	(void)ref;
	std::cout << "this function will never be called, if you see this sentence, something is seriously wrong\n";
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw eUnsigned;
	else if (getGradeToExecute() < executor.getGrade())
		throw eLow;
	else
		std::cout << "[Inform] : " << target << " has been pardoned by Zaphod Beeblebrox\n"; 
}
