#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal's default Constructor is called]\n";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "[Animal " << type << "\'s constructor is called]\n";
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "[Animal's copy constructor is called]\n";
}

Animal::~Animal()
{
	std::cout << "[Animal " << type << "\'s destructor is called]\n";
}
Animal	&Animal::operator=(const Animal &ref)
{
	this->type = ref.type;
	std::cout << "[Animal's assignment is operated]\n";
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "[Animal " << type << " make sound]\n";
} 
std::string	Animal::getType() const {return (type);}
