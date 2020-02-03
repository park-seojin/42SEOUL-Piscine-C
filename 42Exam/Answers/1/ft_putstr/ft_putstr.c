#include <unistd.h>

void	ft_putstr(char *str)
{
	int x = 0;
	while(str[x])
	{
		x++;
	}
	write(1, str, x);
}