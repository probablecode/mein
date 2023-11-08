#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
int	main(void)
{
	setlocale(LC_ALL, "UTF-8");
	char *str[10] = {
		"\u2070",
		"\u00B9",
		"\u00B2",
		"\u00B3",
		"\u2074",
		"\u2075",
		"\u2076",
		"\u2077",
		"\u2078",
		"\u2079",
	};
	write(1,str[0], 3);
	write(1,str[1], 2);
	write(1,str[2], 2);
	write(1,str[3], 2);
	write(1,str[4], 3);
	write(1,str[5], 3);
	write(1,str[6], 3);
	write(1,str[7], 3);
	write(1,str[8], 3);
	write(1,str[9], 3);
	/*	
	printf("%s", "x");
	printf("%s", "\u00B1");
	printf("%s", "\u00B2");
	printf("%s", "\u00B3");
*/
	// wchar_t	a = (wchar_t)"\u2074";

//	wprintf(L"%c\n",L\u2074);
//	char c = '0' + sizeof("\u2079"); 

	//write(1, "x", 1);
	//write(1, "\u2079", 4);
//wprintf(L"%c\n", "\u2074");
	//wchar_t	a = 0xE298A0;
	//wchar_t b = 0xEC9C84;
	//wprintf(L"%c\n", (wchar_t)a);
	//write(1, &a, 4);
	//printf("sizeof(wchar_t) == :%d\n", sizeof(a));	
	//wprintf(L"%c\n", a);
	//wprintf(L"%s\n", L"안녕하세요");
	//0b111011001000101010111001);

	////0xc2b9	
	//1100 0010 1011 1001
	////1110xxxx 10xxxxxx 10xxxxxx
	return (0);
}
