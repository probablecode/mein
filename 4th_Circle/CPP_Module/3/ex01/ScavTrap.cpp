#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "\n[ScavTrap's default constructor called]\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "\n[ScavTrap " << name << " is constructed]\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "\n[ScavTrap " << name << " is copied]\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "\n[ScavTrap " << name << " is destructed]\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	this->name = ref.name;
	this->hitPoints = ref.hitPoints;
	this->energyPoints = ref.energyPoints;
	this->attackDamage = ref.attackDamage;
	std::cout << "\n[ScavTrap's copy assignment is operated]\n";
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints && energyPoints)
	{
		std::cout << "\n[ScavTrap " << name << " attaks " << target\
			<< " causing " << attackDamage << " points of damage!"\
			<< "\n, losing 1 energy point resulting in "\
			<< --energyPoints << " points]\n";
	}
}

void	ScavTrap::guardGate()
{
	if (hitPoints && energyPoints)
		std::cout << "\n[ScavTrap " << getName() << " is now in Gate keeper mode]\n";
}
