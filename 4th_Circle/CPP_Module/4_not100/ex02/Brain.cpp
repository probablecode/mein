#include "Brain.hpp"

Brain::Brain() : thoughtsCount(0)
{
	std::cout << "[Brain's default constructor is called]\n";
}
Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "[Brain's copy constructor is called]\n";
}

Brain::~Brain()
{
	std::cout << "[Brain's destructor is called]\n";
	for (size_t i = 0; i < thoughtsCount; i++)
		std::cout << "[" << i << "] : " << ideas[i] << std::endl;
}

Brain	&Brain::operator=(const Brain &ref)
{
	this->thoughtsCount = ref.thoughtsCount;
	for (size_t i = 0 ; i < this->thoughtsCount; i++)
		this->ideas[i] = ref.ideas[i];
	std::cout << "[Brain's copy assignment is operated]\n";
	return (*this);
}

void	Brain::memory(std::string thought)
{
	ideas[thoughtsCount++] = thought;
}
