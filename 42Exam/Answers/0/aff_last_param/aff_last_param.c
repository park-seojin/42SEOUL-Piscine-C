#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(char *str)
{
	int x = 0;
	while ((str[x] == ' ') || (str[x] == '\t') || (str[x] == '\n'))
	{
		x++;
	}
	while ((str[x] != ' ') && (str[x] != '\t') && (str[x] != '\n') && (str[x] != '\0'))
	{
		ft_putchar(str[x]);
		x++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		first_word(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}