#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#define BRAIN_SIZE 100
class Brain
{
	private	:
		std::string	ideas[BRAIN_SIZE];
		size_t	thoughtsCount;
	public	:
		Brain();
		Brain(const Brain &copy);
		~Brain();
		Brain	&operator=(const Brain &ref);
		void	memory(std::string thought);
};
#endif

