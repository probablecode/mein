#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm()
 : Form("Robotomy", 72, 45), target("void")
{
	std::cout << "RobotomyRequestForm's default constructor is called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string pTarget)
 : Form("Robotomy", 72, 45), target(pTarget)
{
		std::cout << "\nRobotomyRequestForm " << getName()\
			<<"\'s constructor is successfully called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
 : Form(ref), target(ref.target)
{
	std::cout << "RobotomyRequestForm " << getName()\
		<< "\'s copy constructor is called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << getName()\
		<<"\'s destructor is called\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	(void)ref;
	std::cout << "this function will never be called, if you see this sentence, something is seriously wrong\n";
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw eUnsigned;
	else if (getGradeToExecute() < executor.getGrade())
		throw eLow;
	else
	{
		std::cout << "[After Some Drilling Noises..] : ";
		srand((unsigned int)time(NULL));
		if (rand() % 2)
			std::cout << target << " has been robotomized successfully.\n";
		else
			std::cout << target << " has failed to be robotomized\n";
	}
}
