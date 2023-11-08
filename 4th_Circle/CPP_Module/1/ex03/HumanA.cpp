#include "HumanA.hpp"
HumanA::HumanA( std::string name, Weapon &ref):wref(ref)
{
	this->name = name;
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << wref.getType() << std::endl;
}
