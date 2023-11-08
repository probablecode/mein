#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm()
 : Form("Shrubbery", 145, 137), target("void")
{
	std::cout << "ShrubberyCreationForm's default constructor is called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string pTarget)
 : Form("Shrubbery", 145, 137), target(pTarget)
{
		std::cout << "\nShrubberyCreationForm " << getName()\
			<<"\'s constructor is successfully called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
 : Form(ref), target(ref.target)
{
	std::cout << "ShrubberyCreationForm " << getName()\
		<< "\'s copy constructor is called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << getName()\
		<<"\'s destructor is called\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	(void)ref;
	std::cout << "this function will never be called, if you see this sentence, something is seriously wrong\n";
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw eUnsigned;
	else if (getGradeToExecute() < executor.getGrade())
		throw eLow;
	else
	{
		std::ofstream	ofs;
		ofs.open (target + "_shrubbery", std::ofstream::out);
		ofs << "     *        *        *        *        *        *       *    \n";
		ofs << "    /.\\      /.\\      /.\\      /.\\      /.\\      /.\\     /.\\   \n";
		ofs << "   /o..\\    /o..\\    /o..\\    /o..\\    /o..\\    /o..\\   /o..\\  \n";
		ofs << "   /..o\\    /..o\\    /..o\\    /..o\\    /..o\\    /..o\\   /..o\\  \n";
		ofs << "  /.o..o\\  /.o..o\\  /.o..o\\  /.o..o\\  /.o..o\\  /.o..o\\ /.o..o\\ \n";
		ofs << "  /...o.\\  /...o.\\  /...o.\\  /...o.\\  /...o.\\  /...o.\\ /...o.\\ \n";
		ofs << "//..o....\\/..o....\\/..o....\\/..o....\\/..o....\\/..o....\\..o....\\\n";
		ofs << "^^^[_]^^^^^^[_]^^^^^^[_]^^^^^^[_]^^^^^^[_]^^^^^^[_]^^^^^^[_]^^^\n";
		ofs.close();
	}
}
