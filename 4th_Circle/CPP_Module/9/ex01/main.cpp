#include "RPN.hpp"
#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char* argv[]) {
	RPN	rpn;

	if (argc != 2) {
        std::cout << "Need Only One Argument\n"<<"Usage: RPN [Inverted Polish mathematical expression only]\n";
		return (1);
    }
	
	std::string str(argv[1]);
	try {
		for (size_t i = 0; i < str.length(); i++)
		{
			int	ch = str[i];
			if (ch == ' ')
				continue ;
			else if (isdigit(ch))
			{
				size_t j = 0;
				while (isdigit(str[i + j]))
					j++;
				char tmp[16] = {0,};
				rpn.mount(std::atoi(strncpy(tmp, &str[i], j)));
				i += j;
			}
			else
				rpn.operate(ch);
		}
		std::cout << rpn.getResult() << std::endl;
	}
	catch (std::exception &e){std::cout << e.what(); return (1);}
	return (0);
}
