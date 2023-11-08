#include "RPN.hpp"
RPN::RPN(){}
RPN::~RPN(){}
RPN	&RPN::operator=(const RPN &ref)	{(void)ref;return (*this);}
RPN::RPN(const RPN &copy) {(void)copy;}

void	RPN::mount(int digit) {this->stack.push(digit);}
void	RPN::operate(char op)
{
	int	lOperand;
	int	rOperand;

	if (this->stack.empty())
		throw (RPN::InvalidException());
	rOperand = this->stack.top();
	this->stack.pop();
	if (this->stack.empty())
		throw (RPN::InvalidException());
	lOperand = this->stack.top();
	this->stack.pop();
	switch (op) {
		case '+':
			this->stack.push(lOperand + rOperand);
			break;
		case '-':
			this->stack.push(lOperand - rOperand);
			break;
		case '*':
			this->stack.push(lOperand * rOperand);
			break;
		case '/':
			if (rOperand == 0)
				throw (RPN::InvalidException());	
			this->stack.push(lOperand / rOperand);
			break;
		default:
			throw (RPN::InvalidException());	
			break;
	}
}

int		RPN::getResult()
{
	if (this->stack.size() != 1)
		throw (RPN::InvalidException());		
	return (this->stack.top());
}

const char	*RPN::InvalidException::what(void) const throw()
{
	return ("Invalid Argument, Exit..\n");
}
