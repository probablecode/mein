#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;
	const std::string levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc == 2)
	{
		std::string level = argv[1];
		int idx = 0;
		while (idx < 4 && levels[idx] != level)
			idx++;

		switch (idx)
		{
			case 0:
				harl.complain(levels[0]);
			case 1:
				harl.complain(levels[1]);
			case 2:
				harl.complain(levels[2]);
			case 3:
			{
				harl.complain(levels[3]);
				break;
			}
			default :
				std::cout << "[ Probably complaining about insignificant problems ]\n";
		}
	}
	return (0);
}
