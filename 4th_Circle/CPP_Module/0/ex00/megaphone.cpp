#include <iostream>

int	main (int argc, char *argv[])
{
	std::string	concated;

	if (1 < argc)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string	str(argv[i]);
			for (size_t j = 0; j < str.length(); j++)
				concated += std::toupper(str[j]);
		}
	}
	else
		concated = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << concated << std::endl;
	return (0);
}

