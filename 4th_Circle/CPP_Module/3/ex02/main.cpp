#include "FragTrap.hpp"
int main( void )
{
	std::cout << "\n//FragTrap a0(\"jchoi\");";
	FragTrap a0("jchoi");
	
	std::cout << "\n//FragTrap b0(\"norminette\");";
	FragTrap b0("norminette");
	
	std::cout << "\n//a0.attack(b0.getName());";
	a0.attack(b0.getName());
	
	std::cout << "//b0.takeDamage(a0.getAttackDamage());\n";
	b0.takeDamage(a0.getAttackDamage());
	
	std::cout << "\n//b0.attack(a0.getName());";
	b0.attack(a0.getName());
	
	std::cout << "//a0.takeDamage(b0.getAttackDamage());\n";
	a0.takeDamage(b0.getAttackDamage());
	
	std::cout << "\n//FragTrap a1;";
	FragTrap a1;
	
	std::cout << "\n//a1 = a0";
	a1 = a0;

	std::cout << "\n//a1.attack(b0.getName());";
	a1.attack(b0.getName());
	
	std::cout << "//b0.takeDamage(a1.getAttackDamage());\n";
	b0.takeDamage(a1.getAttackDamage());

	std::cout << "\n//FragTrap b1(b0)";
	FragTrap b1(b0);
	
	std::cout << "\n//b1.attack(a1.getName());";
	b1.attack(a1.getName());
	
	std::cout << "//a1.takeDamage(b1.getAttackDamage());\n";
	a1.takeDamage(b1.getAttackDamage());
	
	std::cout << "\n//a1.beRepaired(2);";
	a1.beRepaired(2);
	
	std::cout << "\n[An original " << a0.getName() << " has "\
		<< a0.getHitPoints() << " of hitPoints, but copied "\
		<< a1.getName() << " has " << a1.getHitPoints() << " of hitPoints]\n";

	std::cout << "\n//a0.highFivesGuys();";
	a0.highFivesGuys();
	
	return (0);
}
