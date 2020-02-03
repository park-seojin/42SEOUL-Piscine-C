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

void	ft_union(char *s1, char *s2)
{
	int x = 0;
	int y = 0;
	int z = 0;
	while(s1[x])
	{
		if(ft_compare(s1, s1[x], x) == 0)
		{
			ft_putchar(s1[x]);
		}
		x++;
	}
	z = x;
	while(s2[y])
	{
		if((ft_compare(s1, s2[y], z) == 0) && (ft_compare(s2, s2[y], y)) == 0)
		{
			ft_putchar(s2[y]);
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	ft_putchar('\n');
	return 0;
}