#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <iomanip> 
class Zombie
{
	private :
		std::string name;
	public	:
		Zombie();
		Zombie( std::string str );
		~Zombie();

		void	setName( std::string );
		void	announce( void );
		
		Zombie	*zombieHorde( int N, std::string name );
};
#endif
