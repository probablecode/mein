#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = name;
	std::cout << "ClapTrap " << getName() << " is constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "ClapTrap " << getName() << " is copied\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << getName() << " is destroyed\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	setName(ref.getName());
	setHitPoints(ref.getHitPoints());
	setEnergyPoints(ref.getEnergyPoints());
	setAttackDamage(ref.getAttackDamage());
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (getHitPoints() && getEnergyPoints())
	{
		std::cout << "ClapTrap " << getName()\
			<< " attaks " << target\
			<< " causing " << getAttackDamage()\
			<< " points of damage!\nand losing 1 energy points resulting in ";
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getEnergyPoints() << " energyPoints\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << getName() << " take " << amount <<\
		" of damage, making his Hit points from " << getHitPoints();
	if (getHitPoints() < amount)
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << " to " << getHitPoints() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{	
	if (getHitPoints() && getEnergyPoints())
	{
		std::cout << "ClapTrap " << getName() << " is repaired by "\
			<< amount << " points, making his Hit points from "\
			<< getHitPoints() << " to ";
		setHitPoints(getHitPoints() + amount);
		std::cout << getHitPoints() << "\nand losing 1 energy points resulting in ";
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << getEnergyPoints() << " energyPoints\n";
	}
}

void	ClapTrap::setName(std::string name) {this->name = name;}
void	ClapTrap::setHitPoints(unsigned int hitPoints) {this->hitPoints = hitPoints;}
void	ClapTrap::setEnergyPoints(unsigned int energyPoints) {this->energyPoints = energyPoints;}
void	ClapTrap::setAttackDamage(unsigned int attackDamage) {this->attackDamage = attackDamage;}
std::string	ClapTrap::getName() const {return (name);}
unsigned int	ClapTrap::getHitPoints() const {return (hitPoints);}
unsigned int	ClapTrap::getEnergyPoints() const {return (energyPoints);}
unsigned int	ClapTrap::getAttackDamage() const {return (attackDamage);}
