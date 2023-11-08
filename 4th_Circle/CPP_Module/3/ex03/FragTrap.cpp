#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "\n[FragTrap's default constructor called]\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "\n[FragTrap " << name << " is constructed]\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "\n[FragTrap " << name << " is copied]\n";
}

FragTrap::~FragTrap()
{
	std::cout << "\n[FragTrap " << name << " is destructed]\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	this->name = ref.name;
	this->hitPoints = ref.hitPoints;
	this->energyPoints = ref.energyPoints;
	this->attackDamage = ref.attackDamage;
	std::cout << "\n[FragTrap's copy assignment is operated]\n";
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (hitPoints && energyPoints)
		std::cout << "\n[FragTrap " << getName()\
			<< " use his capacity, \'highFivesGuys\']\n";
}
