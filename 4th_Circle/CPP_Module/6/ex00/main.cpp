#include "Scalar.hpp"
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		try
		{
			Scalar scalar(argv[1]);
			std::cout << scalar;
		}
		catch (std::exception &e)
		{
			std::cout << e.what();
			return (1);
		}
		return (0);
	}
	std::cout << "plz only one argument value!\n";
	return (1);
}
