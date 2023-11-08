#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon *wptr)
{
	this->name = name;
	this->wptr = wptr;
}

void	HumanB::setWeapon( Weapon &ref )
{
	wptr = &ref;
}

void	HumanB::attack( void )
{
	if (wptr != nullptr)
		std::cout << name << " attacks with their " << wptr->getType() << std::endl;
	else
		std::cout << name << " has no weapon. so attack failed.\n";
}
