#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"
class	Cat : public AAnimal
{
	private	:
		Brain	*brain;
	public	:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat	&operator=(const Cat &ref);
		void	makeSound() const;
		void	think(std::string thought);
};
#endif
