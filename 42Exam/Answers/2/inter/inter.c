#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

int		ft_compare(char *str, char c, int i)
{
	while(i >= 0)
	{
		i--;
		if(str[i] == c)
			return 1;
	}
	return 0;
}

void	ft_inter(char *s1, char *s2)
{
	int x = 0;
	int y = 0;
	while(s1[x])
	{
		if(ft_compare(s1, s1[x], x) == 0)
		{
			y = 0;
			while(s2[y])
			{
				if(s1[x] == s2[y])
				{
					ft_putchar(s1[x]);
					break;
				}
				y++;
			}
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 3)
	{
		ft_inter(argv[1], argv[2]);
	}
	ft_putchar('\n');
	return 0;
}