#include "Span.hpp"

Span	&Span::operator=(const Span &ref) {this->vectors = ref.vectors;return (*this);}
Span::Span(const Span &copy) {this->vectors = copy.vectors;}
Span::~Span(){}
Span::Span() : vectors(0, 0) {vectors.reserve(0);}
Span::Span(unsigned int N) : vectors(0, 0) {vectors.reserve(N);}

void	Span::addNumber(int num)
{
	if (vectors.size() < vectors.capacity())
		vectors.push_back(num);
	else
		throw (NoSpaceException());
}

unsigned int	Span::shortestSpan()
{
	if (vectors.size() < 2)
		throw (NoSpanException());

	std::vector<int> tmp(vectors);
	std::sort(tmp.begin(), tmp.end());
	int num = INT_MAX;
	std::vector<int>::iterator iter = tmp.begin();
	
	while (iter + 1 != tmp.end())
	{
		if ((*(iter + 1) - *iter) < num)
			num = (*(iter + 1) - *iter);
		iter++;
	}
	return (num);
}

unsigned int	Span::longestSpan()
{
	if (vectors.size() < 2)
		throw (NoSpanException());
	std::vector<int>::iterator min = std::min_element(vectors.begin(), vectors.end());
	std::vector<int>::iterator max = std::max_element(vectors.begin(), vectors.end());
	return (static_cast<unsigned int>(*max - *min));
}

const char	*Span::NoSpaceException::what(void) const throw()
{
	return ("There's no space for addNumber()\n");
}

const char	*Span::NoSpanException::what(void) const throw()
{
	return ("Span doesn't exist in here\n");
}
