#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie( std::string str )
{
	setName(str);
}

Zombie::~Zombie()
{
	std::cout << name << ": AAAAAAAAAAAAAAAAAA\n";
}

void	Zombie::setName( std::string str )
{
	this->name = str;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

