#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	BitcoinExchange	btcEx;
	std::ifstream btcDateFile("./data.csv");

	if (argc != 2)
	{
		std::cout << "Usage : ./btc [input file only]\n";
		return (1);
	}
	if (!btcDateFile.is_open())
	{
		std::cout << "Error: Cannot open Btc Data File. Exit.. \n";
		return (1);
	}
	btcEx.parseBtcPrice(btcDateFile);
	btcDateFile.close();
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cout << "Error: Cannot open Input File. Exit.. \n";
		return (1);
	}
	btcEx.parseInput(inputFile);
	inputFile.close();
	btcEx.matchingDate();
	btcEx.printResult();
	return (0);
}
