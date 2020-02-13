#include <stdio.h>
#include "ft_convert_base.c"

int main()
{
	char from[ ] = "0123456789";
	char to[ ] = "0123456789";
	char nbr[ ] = "-2148";
//	char nbr2[ ] = "5643213";

	printf("양수 : %s\n", ft_convert_base(nbr, from, to));
	return 0;
}
