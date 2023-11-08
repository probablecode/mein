#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "[AAnimal's default Constructor is called]\n";
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "[AAnimal " << type << "\'s constructor is called]\n";
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "[AAnimal's copy constructor is called]\n";
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal " << type << "\'s destructor is called]\n";
}
AAnimal	&AAnimal::operator=(const AAnimal &ref)
{
	this->type = ref.type;
	std::cout << "[AAnimal's assignment is operated]\n";
	return (*this);
}

std::string	AAnimal::getType() const {return (type);}
