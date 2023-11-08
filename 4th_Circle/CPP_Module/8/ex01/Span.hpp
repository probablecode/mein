#ifndef	SPAN_HPP
#define	SPAN_HPP
#include <climits>
#include <algorithm>
#include <vector>
#include <iostream>
class Span
{
	private	:
		std::vector<int> vectors;
	public	:
		Span();
		~Span();
		Span(const Span &copy);
		Span	&operator=(const Span &ref);
		Span(unsigned int N);
		void	addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
		class NoSpaceException	: public std::exception {
			public	:	const char	*what() const throw();
		};
		class NoSpanException	: public std::exception {
			public	:	const char	*what() const throw();
		};

		template <typename T>
		void	rangeAdd(T begin, T end)
		{
			if (vectors.capacity() - vectors.size() < static_cast<unsigned long>(std::distance(begin, end)))
				throw (NoSpaceException());
			while (begin != end)
				vectors.push_back(*(begin++));
		}
};
#endif
