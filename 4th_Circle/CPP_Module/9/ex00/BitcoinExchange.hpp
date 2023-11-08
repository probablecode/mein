#ifndef	BITCOIN_EXCHANGE_HPP
#define	BITCOIN_EXCHANGE_HPP

#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>

typedef enum stat
{
	DATE,
	BEFORE,
	LARGE,
	NPOS,
	NORMAL
}	stat;

typedef struct Date
{
	int	year;
	int	month;
	int day;

	int		dateValue() const;
	bool	dateValidityCheck();
	void	strToDate(std::string str);
	void	printDate();
	bool	operator>(const struct Date &d) const;
	bool	operator<(const struct Date &d) const;
	bool	operator==(const struct Date &d) const;
}	Date;

typedef struct BtcPrice
{
	Date	date;
	double	price;
}	BtcPrice;

typedef struct BtcValue
{
	Date	inputDate;
	double	amount;
	double	value;
	stat	st;
}	BtcValue;

class BitcoinExchange
{
	private	:
		std::vector<BtcPrice> db;
		std::vector<BtcValue> input;
	public	:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange	&operator=(const BitcoinExchange &ref);

		void	parseBtcPrice(std::ifstream &btcFile);
		void	parseInput(std::ifstream &inputFile);
		void	matchingDate();
		void	printResult();
};
#endif
