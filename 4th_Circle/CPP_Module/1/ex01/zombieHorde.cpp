#include "Zombie.hpp"

Zombie	*Zombie::zombieHorde( int N, std::string name )
{
	if ( 0 < N )
	{	
		Zombie	*zhptr = new Zombie[N];
		for (int i = 0; i < N; i++)
			zhptr[i].setName(name + std::to_string(i));
		return (zhptr);
	}
	else
		return (nullptr);
}
