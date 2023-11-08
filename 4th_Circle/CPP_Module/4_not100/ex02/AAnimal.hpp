#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>
class	AAnimal
{
	protected	:
		std::string	type;
	public	:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();	
		AAnimal	&operator=(const AAnimal &ref);

		virtual void	makeSound() const = 0;
		std::string	getType() const;
};
#endif
