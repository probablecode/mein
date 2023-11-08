#include "Scalar.hpp"
Scalar::Scalar(){std::cout << "something wrong, Default Construct should not be called\n";
	throw (Scalar::InvalidValueException());}
Scalar::Scalar(const Scalar &copy){(void)copy;}
Scalar	&Scalar::operator=(const Scalar &ref){(void)ref;return (*this);}
Scalar::~Scalar(){}

Scalar::Scalar(char *input)
{
	str = input;
	if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff" || str == "nan" || str == "nanf")
	{	
		handlePseudo(str);
		return ;
	}
	else if (strlen(input) == 0)
		throw (Scalar::InvalidValueException());
	else if (strlen(input) == 1 && !std::isdigit(input[0]))
		actualType = CHAR;
	else if (!(input[0] != '-' || input[0] != '+' || std::isdigit(input[0])))
		throw (Scalar::InvalidValueException());
	else
	{
		int i = 1;
		while (std::isdigit(input[i]))
			i++;
		if (input[i] == '\0')
			actualType = INT;
		else if (input[i] !='.')
			throw (Scalar::InvalidValueException());
		else if (!std::isdigit(input[++i]))
			throw (Scalar::InvalidValueException());
		else
		{
			while (std::isdigit(input[i]))
				i++;
			if (input[i] != '\0' && input[i] != 'f')
				throw (Scalar::InvalidValueException());
			else if (input[i] == 'f')
				actualType = FLOAT;
			else
				actualType = DOUBLE;
		}
	}
	handleScalar();
}

void	Scalar::handleScalar()
{
	switch (actualType)
	{
		case CHAR :
			fromChar();
			break;
		case INT :
			fromInt();
			break;
		case FLOAT :
			fromFloat();
			break;
		case DOUBLE:
			fromDouble();
			break;
	}
}

void	Scalar::fromChar()
{
	char raw = str[0];
	if (std::isprint(raw))
		charStr = "\'" + str.substr(0,1) + "\'";
	else
		charStr = "Non displayable";
	iVal = static_cast<int>(raw);
	intStr = std::to_string(iVal);
	fVal = static_cast<float>(raw);
	floatStr = std::to_string(raw) + ".0f";
	dVal = static_cast<double>(raw);
	doubleStr = std::to_string(raw) + ".0";
}

void	Scalar::fromInt()
{
	long rawLong = std::strtol(str.c_str(), NULL, 10);
	
	if (errno == ERANGE || !(INT_MIN <= rawLong && rawLong <= INT_MAX))
		handlePseudo("nan");
	else
	{
		int raw = static_cast<int>(rawLong);
		intStr = std::to_string(raw);
		char cStr[4] = "\' \'";
		if (CHAR_MAX < raw || raw < CHAR_MIN)
			charStr = "impossible";
		else if (!std::isprint(raw))
			charStr = "Non displayable";
		else
		{
			cVal = static_cast<char>(raw);
			cStr[1] = cVal;
			charStr = cStr;
		}
		fVal = static_cast<float>(raw);
		floatStr = std::to_string(raw) + ".0f";
		dVal = static_cast<double>(raw);
		doubleStr = std::to_string(raw) + ".0";
	}
}

void	Scalar::fromFloat()
{
	float rawFloat = std::strtof(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		handlePseudo("nan");
		return ;
	}
	else if (rawFloat == INFINITY)
	{
		handlePseudo("inf");
		return ;
	}
	else if (rawFloat == -INFINITY)
	{
		handlePseudo("-inf");
		return ;
	}
	long lVal = static_cast<long>(rawFloat);
	iVal = static_cast<int>(rawFloat);
	cVal = static_cast<char>(rawFloat);
	if (!(INT_MIN <= lVal && lVal <= INT_MAX))
		intStr = "impossible";
	else
		intStr = std::to_string(iVal);
	if (!(CHAR_MIN <= lVal && lVal <= CHAR_MAX))
		charStr = "impossible";
	else if (!std::isprint(iVal))
		charStr = "Non displayable";
	else {
		char cStr[4] = "\' \'";
		cStr[1] = cVal;
		charStr = cStr;
	}
	floatStr = std::to_string(rawFloat) + "f";
	dVal = static_cast<double>(rawFloat);
	doubleStr = std::to_string(dVal);
}

void	Scalar::fromDouble()
{
	double rawDouble = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		handlePseudo("nan");
		return ;
	}
	else if (rawDouble == INFINITY)
	{
		handlePseudo("inf");
		return ;
	}
	else if (rawDouble == -INFINITY)
	{
		handlePseudo("-inf");
		return ;
	}
	long lVal = static_cast<long>(rawDouble);
	iVal = static_cast<int>(rawDouble);
	cVal = static_cast<char>(rawDouble);
	if (!(INT_MIN <= lVal && lVal <= INT_MAX))
		intStr = "impossible";
	else
		intStr = std::to_string(iVal);
	if (!(CHAR_MIN <= lVal && lVal <= CHAR_MAX))
		charStr = "impossible";
	else if (!std::isprint(iVal))
		charStr = "Non displayable";
	else {
		char cStr[4] = "\' \'";
		cStr[1] = cVal;
		charStr = cStr;
	}
	fVal = static_cast<float>(rawDouble);
	floatStr = std::to_string(fVal) + "f";
	doubleStr = std::to_string(rawDouble);	

}

void	Scalar::handlePseudo(std::string pseudo)
{
	charStr = "impossible";
	intStr = "impossible";
	fVal = NAN;
	dVal = NAN;
	floatStr = std::to_string(fVal) + "f";
	doubleStr = std::to_string(dVal);
	if (pseudo == "inf" || pseudo == "inff")
	{
		fVal = INFINITY;
		floatStr = std::to_string(fVal) + "f";
		dVal = INFINITY;
		doubleStr = std::to_string(dVal);
	}
	else if (pseudo == "-inf" || pseudo == "-inff")
	{
		fVal = -INFINITY;
		floatStr = std::to_string(fVal) + "f";
		dVal = -INFINITY;
		doubleStr = std::to_string(dVal);
	}
}


std::string	Scalar::getCharStr() const {return (charStr);}
std::string	Scalar::getIntStr() const {return (intStr);}
std::string	Scalar::getFloatStr() const {return (floatStr);}
std::string	Scalar::getDoubleStr() const {return (doubleStr);}
std::ostream	&operator<<(std::ostream &os, const Scalar &ref)
{
	os << "char: " << ref.getCharStr() << std::endl;
	os << "int: " << ref.getIntStr() << std::endl;
	os << "float: " << ref.getFloatStr() << std::endl;
	os << "double: " << ref.getDoubleStr() << std::endl;
	return (os);
}

const char	*Scalar::InvalidValueException::what() const throw()
{
	const char *ret = "[Exception Occur] : Invalid Value\n";
	return (ret);
}
