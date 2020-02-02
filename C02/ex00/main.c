#include <stdio.h>
#include "ft_strcpy.c"

int main()
{
	char arr1[ ] = {"123"};
	char arr2[ ] = {"456789"};

	ft_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}
