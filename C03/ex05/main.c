#include "ft_strlcat.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[20] = "hello";
	char arr2[7] = "daelee";
	char brr1[20] = "hello";
	char brr2[7] = "daelee";

	ft_strlcat(arr1, arr2, 8);
	strlcat(brr1, brr2, 8);
	printf("ft의리턴값은... %s\n 진짜리턴값은...%s\n", arr1, brr1);
	return 0;
}
