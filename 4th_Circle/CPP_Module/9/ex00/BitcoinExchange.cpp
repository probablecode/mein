#include "BitcoinExchange.hpp"

int		Date::dateValue() const {return (year * 10000 + month * 100 + day);}
bool	Date::operator>(const Date &d) const {return (this->dateValue() > d.dateValue());}
bool	Date::operator<(const Date &d) const {return (this->dateValue() < d.dateValue());}
bool	Date::operator==(const Date &d) const {return (this->dateValue() == d.dateValue());}

void	Date::printDate()
{
	std::cout << std::setw(4) << std::setfill('0') << year << "-";
	std::cout << std::setw(2) << std::setfill('0') << month << "-";
	std::cout << std::setw(2) << std::setfill('0') << day;
}

bool	Date::dateValidityCheck()
{
	if (year < 0 || 2100 < year)
		return (false);
	if (month <= 0 || 12 < month)
		return (false);
	if (day <= 0 || 31 < day)
		return (false);
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	if (month == 2 && 28 < day && (year % 4 || day != 29))
		return (false);
	return (true);
}

void	Date::strToDate(std::string str)
{
	char date[32] = {0,};
	char	*token = strtok(strcpy(date, str.c_str()), "-");
	this->year = atoi(token);
	token = strtok(NULL, "-");
	this->month = atoi(token);
	token = strtok(NULL, "-");
	this->day = atoi(token);
}

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &ref)	{(void)ref;return (*this);}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {(void)copy;}

static bool	cmp(BtcPrice a, BtcPrice b)
{
	return (a.date < b.date);
}

void	BitcoinExchange::parseBtcPrice(std::ifstream &btcFile)
{
	std::string	line;
	BtcPrice	bPrice;

	while (std::getline(btcFile, line))
	{
		std::istringstream ss(line);
		std::string date, price;
		if (!std::getline(ss, date, ','))
			continue;
		bPrice.date.strToDate(date);
		if (!std::getline(ss, price))
			continue;
		bPrice.price = std::atof(price.c_str());
		this->db.push_back(bPrice);
	}
    std::sort(db.begin(), db.end(), cmp);
}

void	BitcoinExchange::parseInput(std::ifstream &inputFile)
{
	std::string	line;
	BtcValue	bValue;
	const Date birth = this->db[0].date;
	
	while (std::getline(inputFile, line))
	{
		std::istringstream ss(line);
		std::string date, amount;
		if (!std::getline(ss, date, '|'))
			continue;
		bValue.inputDate.strToDate(date);
		if (!std::getline(ss, amount))
			continue;
		bValue.amount = std::atof(amount.c_str());
		if (bValue.inputDate.dateValidityCheck() == false)
			bValue.st = DATE;
		else if (bValue.inputDate < birth)
			bValue.st = BEFORE;
		else if (1000 <= bValue.amount)
			bValue.st = LARGE;
		else if (bValue.amount <= 0)
			bValue.st = NPOS;
		else
			bValue.st = NORMAL;
		this->input.push_back(bValue);
	}
}

void	BitcoinExchange::matchingDate()
{ 
	for (std::vector<BtcValue>::iterator it = this->input.begin(); it < this->input.end(); it++)
	{
		if (it->st == NORMAL)
		{
			std::vector<BtcPrice>::iterator priceIt = this->db.begin();
			while (priceIt->date < it->inputDate)
				priceIt++;
			if (priceIt == this->db.end())
				priceIt--;
			it->value = it->amount * priceIt->price;
		}
	}
}

void	BitcoinExchange::printResult()
{
	for (std::vector<BtcValue>::iterator it = this->input.begin(); it < this->input.end(); it++)
	{
		switch (it->st)
		{
			case DATE:
				std::cout << "Error: bad input => ";
				it->inputDate.printDate();
				std::cout << std::endl;
				break;
			case BEFORE:
				std::cout << "the date is before btc => ";
				it->inputDate.printDate();
				std::cout << std::endl;
				break;
			case LARGE:
				std::cout << "Error: too large a number.\n";
				break;
			case NPOS:
				std::cout << "Error: not a positive number.\n";
				break;
			case NORMAL:
				it->inputDate.printDate();
				std::cout << " => " << it->amount << " = " << it->value << std::endl;
				break;
			default:
				std::cout << "wtf????????????????????\n Invalid Error, Exit.\n";
				exit(1);
				break;	
		}
	}
}
