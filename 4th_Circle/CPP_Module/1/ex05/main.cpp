#include "Harl.hpp"

int	main()
{
	Harl harl;
	const std::string levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		harl.complain(levels[i]);
	return (0);
}
