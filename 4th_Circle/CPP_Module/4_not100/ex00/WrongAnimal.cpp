#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal's default Constructor is called]\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "[WrongAnimal " << type << "\'s constructor is called]\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "[WrongAnimal's copy constructor is called]\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal " << type << "\'s destructor is called]\n";
}
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref)
{
	this->type = ref.type;
	std::cout << "[WrongAnimal's assignment is operated]\n";
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal " << type << " make sound]\n";
} 
std::string	WrongAnimal::getType() const {return (type);}
