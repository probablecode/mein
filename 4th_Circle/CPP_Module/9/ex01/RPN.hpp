#ifndef	RPN_HPP
#define	RPN_HPP
#include <stack>

class RPN
{
	private	:
		std::stack<int> stack;
	public	:
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN	&operator=(const RPN &ref);
		void	mount(int digit);
		void	operate(char op);
		int		getResult();

		class InvalidException	: public std::exception {
			public	:	const char	*what() const throw();
		};
};
#endif
