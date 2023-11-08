#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("defalut")
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);	
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	ScavTrap();
	std::cout << "ScavTrap " << getName() << " is constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.getName())
{
	*this = copy;
	std::cout << "ScavTrap " << getName() << " is copied\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " is destructed\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	setName(ref.getName());
	setHitPoints(ref.getHitPoints());
	setEnergyPoints(ref.getEnergyPoints());
	setAttackDamage(ref.getAttackDamage());
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() && getEnergyPoints())
	{
		std::cout << "ScavTrap " << getName()\
			<< " attaks " << target\
			<< " causing " << getAttackDamage()\
			<< " points of damage!\nand losing 1 energy points resulting in ";
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getEnergyPoints() << " energyPoints\n";
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << getName() << " take " << amount <<\
		" of damage, making his Hit points from " << getHitPoints();
	if (getHitPoints() < amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << " to " << getHitPoints() << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{	
	if (getHitPoints() && getEnergyPoints())
	{
		std::cout << "ScavTrap " << getName() << " is repaired by "\
			<< amount << " points, making his Hit points from "\
			<< getHitPoints() << " to ";
		setHitPoints(getHitPoints() + amount);
		std::cout << getHitPoints() << "\nand losing 1 energy points resulting in ";
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getEnergyPoints() << " energyPoints\n";
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode.\n";
}
