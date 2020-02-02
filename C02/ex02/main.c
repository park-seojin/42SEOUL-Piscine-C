#include "ft_str_is_alpha.c"
#include <stdio.h>

int main()
{
	int test = 0;

	char arr[ ] = {'.', '_'};
	test = ft_str_is_alpha(arr);
	printf("%d\n", test);
}
