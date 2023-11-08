#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class	FragTrap : virtual public ClapTrap
{
	public	:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &ref);
		void	highFivesGuys(void);
};
#endif