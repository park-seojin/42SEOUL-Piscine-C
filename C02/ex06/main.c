#include "ft_str_is_printable.c"
#include <stdio.h>

int main()
{
	int test = 0;

	char arr[ ] = {'0', 'W'};
	test = ft_str_is_printable(arr);
	printf("%d\n", test);
}
