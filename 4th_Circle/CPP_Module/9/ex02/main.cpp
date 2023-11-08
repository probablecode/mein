#include "PmergeMe.hpp"
int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "Error: please enter a sequence of positive integers as arguments." << std::endl;
		return (1);
	}
	PmergeMe	pm;
	for (int i = 1; i < argc; i++)
	{
		int num = std::atoi(argv[i]);
		if (num <= 0)
		{
			std::cout << "Error: invalid input, please enter only positive integers." << std::endl;
			return (1);
		}
		pm.fillNumber(num);
	}
	try {
		double	tList, tDeque;
		pm.printContainers();
		tList = pm.sortList();
		tDeque = pm.sortDeque();
		pm.printContainers();
		std::cout << "Time to process a range of " << argc - 1\
			<< " elements with PmergeMe::sortList() : " << tList << " us\n";	
		std::cout << "Time to process a range of " << argc - 1\
			<< " elements with PmergeMe::sortDeque() : " << tDeque << " us\n";
	}
	catch (std::exception &e){std::cout << e.what(); return (1);}
	return (0);
}
