#include "ft_ultimate_div_mod.c"
#include <stdio.h>

int main()
{
	int a = 42;
	int b = 10;

	ft_ultimate_div_mod(&a, &b);
	printf("%d, %d", a, b);
	return 0;
}
