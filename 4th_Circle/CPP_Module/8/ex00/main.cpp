#include "easyfind.hpp"
#include <iostream>
#include <vector>
int	main( void )
{
	std::vector <int> vectors;

	for (int i = 0; i < 10; i++)
		vectors.push_back(i*i);

	std::cout << "std::vector<int> vectors\n\nfor (int i = 0; i < 10; i++)\n\tvectors.push_back(i*i);\n";
	
	int input;
	std::cout << "input : ";
	std::cin >> input;

	std::cout << "*(easyfind(vectors, input)) : ";
	try {std::cout << *(easyfind(vectors, input)) << std::endl;}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl;
	return 0;
}
