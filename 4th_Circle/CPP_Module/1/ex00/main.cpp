#include "Zombie.hpp"

int	main( void )
{
	Zombie z1("jchoi");

	std::cout << "\njchoi announce [jchoi.announce();]\n";
	z1.announce();

	std::cout << "\njchoi use randomChump foo [jchoi.randomChump(\"foo\");]\n";
	z1.randomChump("foo");

	std::cout << "\njchoi use newZombie shit[Zombie *zptr = jchoi.newZombie(\"shit\");]\n";
	Zombie *zptr = z1.newZombie("shit");
	
	std::cout << "\nthe first new Zombie announce [zptr->announce();]\n";
	zptr->announce();
	
	std::cout << "\nthe  Zombie use newZombie bullshit [Zombie *zzptr = zptr->newZombie(\"bullshit\")]\n";
	Zombie *zzptr = zptr->newZombie("bullshit");
	
	std::cout << "\nthe second new Zombie announce [zzptr->announce();]\n";
	zzptr->announce();

	std::cout << "\nthe first new Zombie is destroyed[delete zptr;]\n";
	delete zptr;

	std::cout << "\nthe second new Zombie is destroyed[delete zzptr;]\n";
	delete zzptr;

	std::cout << "\nthe simulation End, there will be following jchoi's Screaming..\n";
	return (0);
}
