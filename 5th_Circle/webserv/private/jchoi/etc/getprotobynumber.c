#include <stdio.h>
#include <netdb.h>

int main() {

	struct protoent *proto;
	for (int i = -100; i < 0; i++)
	{
		printf("[row (%d)] : ", i);
		proto = getprotobynumber(i);
		if (proto == NULL)
			printf("there's no protocol numbered as %d\n", i);
		else {
			printf("Protocol Name: [%s]", proto->p_name);
			if (proto->p_aliases)
			{
				for (int j = 0; proto->p_aliases[j]; j++)
					printf(" | [%s]", proto->p_aliases[j]);
			}
			printf("\n");
		}
    }
    return 0;
}
