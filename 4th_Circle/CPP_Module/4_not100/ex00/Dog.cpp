#include "Dog.hpp"
Dog::Dog() : Animal("Dog")
{
	std::cout << type << "\'s default constructor is called\n";
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << type << "\'s copy constructor is called\n";
}

Dog::~Dog()
{
	std::cout << type << "\'s destructor is called\n";
}
	
Dog	&Dog::operator=(const Dog &ref)
{
	this->type = ref.type;
	std::cout << type << "\'s assignment is operated\n";
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "\'Arsenal\'\n";
}
