#include "ft_strlowcase.c"
#include <stdio.h>

int main()
{
	char arr[ ] = "a1234ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_strlowcase(arr);
	printf("%s\n", arr);

	return 0;
}
