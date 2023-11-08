#include "MutantStack.hpp"
#include <list>
int main()
{
	std::list<int> mList;
	mList.push_back(5);
	mList.push_back(17);
	std::cout << mList.back() << std::endl;
	mList.pop_back();
	std::cout << mList.size() << std::endl;
	mList.push_back(3);
	mList.push_back(5);
	mList.push_back(737);
	//[...]
	mList.push_back(0);
	std::list<int>::iterator lit = mList.begin();
	std::list<int>::iterator lite = mList.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> ls(mList);

	//==============================================================
	std::cout << "//=============================================\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	return 0;
}
