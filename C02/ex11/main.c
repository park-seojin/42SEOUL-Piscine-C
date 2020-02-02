#include "ft_putstr_non_printable.c"
#include <stdio.h>

int main()
{
	char arr[ ] = "\xff Coucou\ntu vas bien ?";
	ft_putstr_non_printable(arr);
	return 0;
}
