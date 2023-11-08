#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int	main(void)
{
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	const Animal	*i = new Dog();
	std::cout << std::endl;
	const Animal	*j = new Cat();
	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;	
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	
	delete i;
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;


	const WrongAnimal	*wMeta = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal	*wI = new WrongCat();
	std::cout << std::endl;
	const WrongCat		*cmp = new WrongCat();
	std::cout << std::endl;

	wI->makeSound();
	wMeta->makeSound();
	cmp->makeSound();
	std::cout << std::endl;
	
	delete wI;
	std::cout << std::endl;
	delete wMeta;
	std::cout << std::endl;
	delete cmp;

	return (0);
}
