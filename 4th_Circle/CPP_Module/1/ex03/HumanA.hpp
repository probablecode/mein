#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include "Weapon.hpp"
class HumanA
{
	private :
		std::string name;
		Weapon	&wref;
	public	:
		HumanA( std::string name, Weapon &ref );
		void	attack( void );
};
#endif
