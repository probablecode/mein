#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include "Weapon.hpp"
class HumanB
{
	private	:
		std::string name;
		Weapon	*wptr;
	public	:
		HumanB( std::string name, Weapon *wptr = nullptr);
		void	setWeapon( Weapon &ref );
		void	attack( void );
};
#endif
