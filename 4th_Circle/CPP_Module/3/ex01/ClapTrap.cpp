#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("void"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "\n[ClapTrap's default constructor called]\n";
}

ClapTrap::ClapTrap(std::string name)
	: hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = name;
	std::cout << "\n[ClapTrap " << name << " is constructed]\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "\n[ClapTrap " << name << " is copied]\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "\n[ClapTrap " << name << " is destructed]\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	this->name = ref.name;
	this->hitPoints = ref.hitPoints;
	this->energyPoints = ref.energyPoints;
	this->attackDamage = ref.attackDamage;
	std::cout << "\n[ClapTrap's copy assignment is operated]\n";
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "\n[ClapTrap " << name << " attaks " << target\
			<< " causing " << attackDamage << " points of damage!"\
			<< "\n, losing 1 energy point resulting in "\
			<< --energyPoints << " points]\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "[" << name << " take " << amount\
			<< " of damage, making his Hitpoints from " << hitPoints;
		hitPoints = (hitPoints - amount) * (amount < hitPoints);
		std::cout << " to " << hitPoints << "]\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{	
	if (hitPoints && energyPoints)
	{
		std::cout << "\n[" << name << " is repaired by "\
			<< amount << " points, making his Hit points from "\
			<< hitPoints << " to ";
		hitPoints += amount;
		std::cout << hitPoints << "\n, losing 1 energy point resulting in "\
			<< --energyPoints << " points]\n";
	}
}

std::string	ClapTrap::getName() const {return (name);}
unsigned int	ClapTrap::getHitPoints() const {return (hitPoints);}
unsigned int	ClapTrap::getEnergyPoints() const {return (energyPoints);}
unsigned int	ClapTrap::getAttackDamage() const {return (attackDamage);}
