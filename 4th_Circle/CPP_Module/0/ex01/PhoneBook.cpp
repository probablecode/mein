#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>

namespace jchoi
{
	int getUserInput(std::string &input)
	{
		while (1)
		{
			std::getline(std::cin, input);
			if (std::cin.eof())
			{
				std::cout << "\nEOF just entered, Exiting Program\n";
				return (EOF);
			}
			else if (input.empty())
			{
				std::cout << "you just enter the empty string. try again\n";
				continue;
			}
        	else
				return (0);
		}
	}
}

PhoneBook::PhoneBook()
{
	this->contCount = 0;
	this->curIndex = 0;
}

int	PhoneBook::getCommand()
{
	std::string	command;
	
	std::cout << "PhoneBook : \"Enter the command\"\n(usage : ADD, SEARCH, EXIT) >> ";
	if (jchoi::getUserInput(command) == EOF)
		return (EOF);
	else if (command == "ADD")
		return (this->commandAdd());
	else if (command == "SEARCH")
		return (this->commandSearch());
	else if (command == "EXIT")
		return (this->commandExit());
	return (0);
}

int	PhoneBook::commandAdd()
{
	Contact	&contact = this->contacts[this->curIndex];
	std::string	buf;

	std::cout << "PhoneBook : \"ADD, save a new contact\"\n";
	std::cout << "=====================================\n";
	std::cout << "| Please enter each field correctly |\n";
	std::cout << "=====================================\n";
	
	std::cout << "first name : ";	
	if (jchoi::getUserInput(buf) == EOF)
		return (EOF);
	contact.setFirstName(buf);

	std::cout << "last name : ";	
	if (jchoi::getUserInput(buf) == EOF)
		return (EOF);
	contact.setLastName(buf);

	std::cout << "nick name : ";	
	if (jchoi::getUserInput(buf) == EOF)
		return (EOF);
	contact.setNickName(buf);

	std::cout << "phone number : ";	
	if (jchoi::getUserInput(buf) == EOF)
		return (EOF);
	contact.setPhoneNumber(buf);

	std::cout << "darkest secret : ";	
	if (jchoi::getUserInput(buf) == EOF)
		return (EOF);
	contact.setDarkestSecret(buf);

	std::cout << "PhoneBook : \"Adding a new Contact is succesfully done\"\n\n";	
	this->curIndex = (this->curIndex + 1) % this->phoneBookSize;
	if (this->contCount < this->phoneBookSize)
		this->contCount++;
	return (true);
}

int	PhoneBook::commandSearch()
{
	std::string	buf;

	if (this->contCount == 0)
	{
		std::cout << "PhoneBook : \"The PhoneBook is empty,\
			Please Add a contact in it first\"\n\n";
		return (0);
	}
	std::cout << "PhoneBook : \"SEARCH, display a specific contact\"";	
	std::cout << "\n-------------------------------------------\n";
	std::cout << std::setw(10) <<"index" << "|";
	std::cout << std::setw(10) <<"first name" << "|";
	std::cout << std::setw(10) <<"last name" << "|";
	std::cout << std::setw(10) <<"nickname";
	std::cout << "\n-------------------------------------------\n";
	
	for (int i = 0; i < this->contCount; i++)
	{
		Contact	&cont = this->contacts[i];
		std::cout << std::setw(10) << i << "|";
		cont.abbr();
	}
	std::cout << "\n-------------------------------------------\n";
	
	while (1)
	{
		std::cout << "type the index number you want (from 0 to " << this->contCount - 1 << ") : ";
		if (jchoi::getUserInput(buf) == EOF)
			return (EOF);
		
		bool isNumber = true;
		size_t i = 0;
		while (i < buf.length() && isNumber == true)
			isNumber = std::isdigit(buf[i++]);
		if (isNumber == false)
		{
			std::cout << "PhoneBook : \"it's not a number, please type valid index\"\n";
			continue;
		}
		int index = std::atoi(buf.c_str());
		if (0 <= index && index < this->contCount)
		{
			Contact &ref = this->contacts[index];
			ref.detail();
			break;
		}
		else
		{
			std::cout << "PhoneBook : " << index << " is out of bound\n";
			continue;
		}
	}
	return (0);
}

int	PhoneBook::commandExit()
{
	std::cout << "EXIT just entered, Exiting Program\n";
	return (EOF);
}

int main(void)
{
	PhoneBook pb;

	while (1)
	{
		if (pb.getCommand() == EOF)
			break;
	}
	return (0);
}
