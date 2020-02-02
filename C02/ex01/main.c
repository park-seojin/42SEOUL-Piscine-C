#include <stdio.h>
#include "ft_strncpy.c"

int main()
{
	char dest[ ] = "123456789";
	char src[ ] = "abc";

	ft_strncpy(dest, src, 2);
	printf("%s\n", dest);
	return 0;
}
