#include "Cat.hpp"
#include "Dog.hpp"
int	main(void)
{
	const AAnimal	*j = new Dog();
	std::cout << std::endl;
	const AAnimal	*i = new Cat();
	std::cout << std::endl;

	i->makeSound();
	std::cout << std::endl;
	j->makeSound();
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;

	return (0);
}
