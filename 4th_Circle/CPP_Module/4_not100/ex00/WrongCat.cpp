#include "WrongCat.hpp"
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << type << "\'s default constructor is called\n";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << type << "\'s copy constructor is called\n";
}

WrongCat::~WrongCat()
{
	std::cout << type << "\' destructor is called\n";
}
	
WrongCat	&WrongCat::operator=(const WrongCat &ref)
{
	this->type = ref.type;
	std::cout << type << "\'s assignment is operated\n";
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Don't take a look.\n";
}
