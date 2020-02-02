#include "ft_strlcpy.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[ ] = {"abcdef"};
	char arr2[ ] = {"123"};
	char brr1[ ] = {"abcdef"};
	char brr2[ ] = {"123"};
	unsigned int a;
	unsigned int b;

	a = ft_strlcpy(arr1, arr2, 0);
	printf("%s\n", arr1);
	printf("%d\n", a);
	printf("--------------\n");
	b = strlcpy(brr1, brr2, 0);
	printf("%s\n", brr1);
	printf("%d\n", b);

	return 0;
}
