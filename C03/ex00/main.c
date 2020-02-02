#include "ft_strcmp.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[ ] = "abc";
	char arr2[ ] = "abcd";
	int ret;
	int ft_ret;

	ft_ret = ft_strcmp(arr1, arr2);
	ret = strcmp(arr1, arr2);
	printf("ft의리턴값은... %d 진짜리턴값은...%d\n", ft_ret, ret);
}
