#include "Zombie.hpp"

int	main( void )
{
	std::cout << "there is Zombie jchoi announce [Zombie z1(\"jchoi\");\n";
	Zombie z1("jchoi");

	std::cout << "\njchoi announce [z1.announce();]\n";
	z1.announce();

	std::cout << "\n jchoi use zombieHorde of 7 zombies\
		\n[Zombie	*ptr = z1.zombieHorde(7, \"foo\")]\n";
	Zombie	*ptr = z1.zombieHorde(7, "foo");

	std::cout << "\nzombieHorde announce \
		\n/*\
		\nfor(int i = 0; i < 7; i++)\
		\n\tptr[i].announce();\
		\n*/\n";
	for (int i = 0; i < 7; i++)
		ptr[i].announce();
	
	std::cout << "\nthe Zombies are destroyed[delete []ptr;]\
		\nthere will be 7 times of screaming from the zombieHorde..\n";
	delete []ptr;

	std::cout << "\nthe simulation End, there will be following jchoi's Screaming..\n";
	return (0);
}
