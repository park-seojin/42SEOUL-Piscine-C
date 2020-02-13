#include <stdio.h>
#include "ft_strdup.c"

int		main(void)
{
	char arr[ ] = "hello world!";

	printf("%s\n", ft_strdup(arr));
	return (0);
}
