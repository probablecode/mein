#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	char *ret;

	fd = open("./hohohoho", O_RDONLY);
	ret = get_next_line(fd);
	while (ret)
	{
		printf("%s",ret);
		if (ret)
			free(ret);
		ret = get_next_line(fd);
	}
	return (0);
}
