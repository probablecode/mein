#ifndef	PmergeMe_HPP
#define	PmergeMe_HPP
#include <list>
#include <deque>
#include <iostream>
#include <sys/time.h>
class PmergeMe
{
	private	:
		std::list<int> list_;
		std::deque<int> deque_;
		std::list<int>	mergeInsertList(std::list<int> toMerge);
		std::deque<int>	mergeInsertDeque(std::deque<int> toMerge);
	public	:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe	&operator=(const PmergeMe &ref);
		void	fillNumber(int number);
		void	printContainers();
		double	sortList();
		double	sortDeque();
		class InvalidException	: public std::exception {
			public	:	const char	*what() const throw();
		};
};
#endif
