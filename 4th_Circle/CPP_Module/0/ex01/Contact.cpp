#include "Contact.hpp"

std::string Contact::strResize(std::string str)
{
	if (10 < str.length())
		return (str.substr(0,9) + '.');
	else
		return (str.substr(0,10));
}
void	Contact::setFirstName(std::string str)
{
	this->firstName = str;
}
void	Contact::setLastName(std::string str)
{
	this->lastName = str;
}		
void	Contact::setNickName(std::string str)
{
	this->nickName = str;
}		
void	Contact::setPhoneNumber(std::string str)
{
	this->phoneNumber = str;
}		
void	Contact::setDarkestSecret(std::string str)
{
	this->darkestSecret = str;
}		

std::string	Contact::getFirstName()
{
	return (this->firstName);
}
std::string	Contact::getLastName()
{
	return (this->lastName);
}
std::string	Contact::getNickName()
{
	return (this->nickName);
}
std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}
void	Contact::abbr()
{
	std::cout << std::setw(10) << strResize(this->getFirstName()) << "|";
	std::cout << std::setw(10) << strResize(this->getLastName()) << "|";
	std::cout << std::setw(10) << strResize(this->getNickName()) << std::endl;
}
void	Contact::detail()
{
	std::cout << "[  first name  ] : " << this->getFirstName() << std::endl;
	std::cout << "[   last name  ] : " << this->getLastName() << std::endl;
	std::cout << "[   nickname   ] : " << this->getNickName() << std::endl;
	std::cout << "[ phone number ] : " << this->getPhoneNumber() << std::endl;
	std::cout << "[darkest secret] : " << this->getDarkestSecret() << std::endl;
}
