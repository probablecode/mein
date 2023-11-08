#ifndef SCALAR_HPP
#define SCALAR_HPP
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
class Scalar
{
	private	:
		std::string str;
		int		actualType;
		
	
		char	cVal;
		int		iVal;
		float	fVal;
		double	dVal;
		
		std::string	intStr;
		std::string charStr;
		std::string floatStr;
		std::string doubleStr;

		class InvalidValueException : public std::exception {
			const char	*what() const throw();};
	public	:
		Scalar();
		Scalar(char *input);
		Scalar(const Scalar &copy);
		~Scalar();
		Scalar	&operator=(const Scalar &ref);

		void	fromChar();
		void	fromInt();
		void	fromFloat();
		void	fromDouble();

		void	handleScalar();
		void	handlePseudo(std::string pseudo);

		std::string	getCharStr() const;
		std::string	getIntStr() const;
		std::string	getFloatStr() const;
		std::string	getDoubleStr() const;
};
std::ostream	&operator<<(std::ostream &os, const Scalar &ref);
#endif
