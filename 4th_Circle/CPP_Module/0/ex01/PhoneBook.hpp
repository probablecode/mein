#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
class PhoneBook
{
	const static int phoneBookSize = 8;
	private :
		Contact	contacts[phoneBookSize];
		int		contCount;
		int		curIndex;
		
		int		commandAdd();
		int		commandSearch();
		int		commandExit();
	public	:
		PhoneBook();
		int		getCommand();
};

#endif
