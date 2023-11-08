#include <stdio.h>
int	main(void)
{
	int *ptr;
	printf("%p\n%.16p\n",ptr,ptr);
	printf("%.17P\n%.16p\n",NULL,NULL);
	return(0);
}
