#include "Cat.hpp"
Cat::Cat() : Animal("Cat")
{
	std::cout << type << "\'s default constructor is called\n";
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << type << "\'s copy constructor is called\n";
}

Cat::~Cat()
{
	std::cout << type << "\'s destructor is called\n";
}
	
Cat	&Cat::operator=(const Cat &ref)
{
	this->type = ref.type;
	std::cout << type << "\'s assignment is operated\n";
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Take a look.\n";
}
