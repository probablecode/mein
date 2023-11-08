#include "Cat.hpp"
Cat::Cat() : AAnimal("Cat")
{
	brain = new Brain();
	std::cout << "[" << type << "\'s default constructor is called]\n";
}

Cat::Cat(const Cat &copy)
{
	brain = new Brain();
	*this = copy;
	std::cout << "[" << type << "\'s copy constructor is called]\n";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "[" << type << "\'s destructor is called]\n";
}
	
Cat	&Cat::operator=(const Cat &ref)
{
	this->type = ref.type;
	*(this->brain) = *(ref.brain);
	std::cout << "[" << type << "\'s assignment is operated]\n";
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Take a look.\n";
}

void	Cat::think(std::string thought)
{
	std::cout << "Cat thinks : (\'" << thought << "\')\n";
	brain->memory(thought);
}
