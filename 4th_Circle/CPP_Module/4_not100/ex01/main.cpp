#include "Cat.hpp"
#include "Dog.hpp"
int	main(void)
{
	Dog dog;
	std::cout << std::endl;
	Cat	cat;
	std::cout << std::endl;

	dog.think("I'm hungry");
	dog.think("Arsenal is best team");
	dog.think("I wanna go outside");	
	cat.think("Meow");
	cat.think("I wanna sleep");
	std::cout << std::endl;

	
	Animal	*animals[4];
	for (int k = 0; k < 4; k++)
	{
		if (k % 2)
			animals[k] = new Dog(dog);
		else
			animals[k] = new Cat(cat);
		std::cout << std::endl;
	}

	for (int k = 0; k < 4; k++)
	{
		animals[k]->makeSound();
		std::cout << std::endl;
	}
	for (int k = 0; k < 4; k++)
	{
		delete(animals[k]); 
		std::cout << std::endl;
	}
	
	return (0);
}
