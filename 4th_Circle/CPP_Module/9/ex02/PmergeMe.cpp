#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe	&PmergeMe::operator=(const PmergeMe &ref)	{(void)ref;return (*this);}
PmergeMe::PmergeMe(const PmergeMe &copy) {(void)copy;}

void	PmergeMe::fillNumber(int number) {
	this->list_.push_back(number);
	this->deque_.push_back(number);
}

std::list<int>	PmergeMe::mergeInsertList(std::list<int> toMerge)
{
	std::list<int> merged, left, right;

	if (toMerge.size() <= 1)
		return (toMerge);
	merged.resize(toMerge.size());
    int middle = toMerge.size() / 2;
    int i = 0;
    for(std::list<int>::iterator it = toMerge.begin(); it != toMerge.end(); it++)
	{
		if (i++ < middle)
			left.push_back(*it);
		else
			right.push_back(*it);
    }
    left = mergeInsertList(left);
    right = mergeInsertList(right);
	std::merge(left.begin(),left.end(), right.begin(), right.end(), merged.begin());
	return (merged);
}

std::deque<int>	PmergeMe::mergeInsertDeque(std::deque<int> toMerge)
{
	std::deque<int> merged, left, right;

	if (toMerge.size() <= 1)
		return (toMerge);
	merged.resize(toMerge.size());
	int	middle = toMerge.size() / 2;
	int	i = 0;
    for (std::deque<int>::iterator it = toMerge.begin(); it != toMerge.end(); it++)
	{
		if (i++ < middle)
			left.push_back(*it);
		else
			right.push_back(*it);
	}
	left = mergeInsertDeque(left);
	right = mergeInsertDeque(right);
	std::merge(left.begin(),left.end(), right.begin(), right.end(), merged.begin());
	return (merged);
}

double	PmergeMe::sortList()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	double start = tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
	this->list_ = mergeInsertList(this->list_);
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + (double)tv.tv_usec - start);
}

double	PmergeMe::sortDeque()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	double start = tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
	this->deque_ = mergeInsertDeque(this->deque_);
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + (double)tv.tv_usec - start);
}

void	PmergeMe::printContainers()
{
	std::list<int>::iterator li = this->list_.begin();
	std::deque<int>::iterator dq = this->deque_.begin();

	std::cout << "elements : ";
	while (li != this->list_.end() && dq != this->deque_.end())
	{
		if (*li != *dq)
			throw (PmergeMe::InvalidException());
		std::cout << *li << " ";
		li++;
		dq++;
	}
	std::cout << std::endl;
}

const char	*PmergeMe::InvalidException::what(void) const throw()
{return ("Invalid Exception Occurs, Exit..\n");}
