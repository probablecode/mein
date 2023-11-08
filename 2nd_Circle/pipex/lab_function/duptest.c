#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int	main(void)
{
	int tmp = open("./test.txt", O_RDONLY);
	int fd = dup(tmp);
	char buffer1[32];
	char buffer2[32];
	int len1 = read(tmp, buffer1, 16); 
	int len2 = read(fd, buffer2, 16);
	printf(" tmp %d\n", tmp);
	printf(" fd %d\n", fd);
	write(1, buffer1, 16);
	write(1, "\n", 1);
	write(1, buffer2, 16);
	write(1, "\n", 1);
	close(tmp);
	close(fd);
	return (0);
}
