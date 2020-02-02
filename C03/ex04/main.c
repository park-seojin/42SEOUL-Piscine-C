#include "ft_strstr.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char str[30] = "abcecdef";
	char *find = ft_strstr(str, "cd");
	char *find2 = strstr(str, "cd");

	printf("내가 만든 리턴은...%s\n 진짜 리턴은...%s\n", find, find2);
	return 0;
}
