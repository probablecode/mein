#include "ScavTrap.hpp"
int main( void )
{
	ScavTrap	a("jchoi");
	a.attack("mooyaho");
	a.takeDamage(4);
	a.beRepaired(3);
	a.guardGate();
	return 0;
}
