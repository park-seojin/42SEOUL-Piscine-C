#include "ft_strupcase.c"
#include <stdio.h>

int main()
{
	char arr[ ] = "A1234abcdefghijklmnopqrstuvwxyz";
	ft_strupcase(arr);
	printf("%s\n", arr);

	return 0;
}
