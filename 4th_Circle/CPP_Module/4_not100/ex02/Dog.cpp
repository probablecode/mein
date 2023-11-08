#include "Dog.hpp"
Dog::Dog() : AAnimal("Dog")
{
	brain = new Brain();
	std::cout << "[" << type << "\'s default constructor is called]\n";
}

Dog::Dog(const Dog &copy)
{
	brain = new Brain();
	*this = copy;
	std::cout << "[" << type << "\'s copy constructor is called]\n";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "[" << type << "\'s destructor is called]\n";
}
	
Dog	&Dog::operator=(const Dog &ref)
{
	this->type = ref.type;
	*(this->brain) = *(ref.brain);
	std::cout << "[" << type << "\'s assignment is operated]\n";
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "\'Arsenal\'\n";
}

void	Dog::think(std::string thought)
{
	std::cout << "Dog thinks : (\'" << thought << "\')\n";
	brain->memory(thought);
}
