#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int x = 0;
	while(str[x])
	{
		if(str[x] >= 'a' && str[x] <= 'm')
			ft_putchar(str[x] + 13);
		else if(str[x] >= 'n' && str[x] <= 'z')
			ft_putchar(str[x] - 13);
		else if(str[x] >= 'A' && str[x] <= 'M')
			ft_putchar(str[x] + 13);
		else if(str[x] >= 'N' && str[x] <= 'Z')
			ft_putchar(str[x] - 13);
		else
			ft_putchar(str[x]);
		x++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 2)
	{
		rot_13(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
