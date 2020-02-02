#include "ft_str_is_numeric.c"
#include <stdio.h>

int main()
{
	int test = 0;
	
	char arr[ ] = "12";
	test = ft_str_is_numeric(arr);
	printf("%d\n", test);
	return 0;
}
