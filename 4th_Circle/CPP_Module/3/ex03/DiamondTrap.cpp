#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
 : name(ClapTrap::name)
{
	ClapTrap::name = name + "_clap_name";
	energyPoints = 50;
	std::cout << "\n[DiamondTrap's default constructor called]\n";
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	energyPoints = 50;
	std::cout << "\n[DiamondTrap " << name << " is constructed]\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), name(copy.name)
{
	ClapTrap::name = name + "_clap_name";
	energyPoints = 50;
	std::cout << "\n[DiamondTrap " << name << " is copied]\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\n[DiamondTrap " << name << " is destructed]\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->name = ref.name;
	this->hitPoints = ref.hitPoints;
	this->energyPoints = ref.energyPoints;
	this->attackDamage = ref.attackDamage;
	std::cout << "\n[DiamondTrap's copy assignment is operated]\n";
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Mein Name ist " << this->name\
		<< ", und mein Name als ein ClapTrap ist " << ClapTrap::name\
		<< std::endl;
}
