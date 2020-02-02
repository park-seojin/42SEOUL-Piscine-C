#include "ft_strncmp.c"
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[ ] = "abce";
	char arr2[ ] = "abcd";
	int ret;
	int ft_ret;

	ft_ret = ft_strncmp(arr1, arr2, 4);
	ret = strncmp(arr1, arr2, 4);
	printf("ft의리턴값은... %d 진짜리턴값은...%d\n", ft_ret, ret);
}
