#include "Zombie.hpp"

Zombie::Zombie( std::string str )
{
	this->name = str;
}

Zombie::~Zombie()
{
	std::cout << name << ": AAAAAAAAAAAAAAAAAA\n";
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

