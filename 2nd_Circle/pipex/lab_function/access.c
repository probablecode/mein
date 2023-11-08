#include <unistd.h>
int	main(void)
{
	if (!access("./moooo", 1))
		write(1, "있음", 6);
	else
		write(1, "없음", 6);
	return (0);
}
