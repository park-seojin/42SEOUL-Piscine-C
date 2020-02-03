#include <unistd.h>

void	rostring(char *s)
{
	int x = 0;
	int y = 0;

	while(s[x] == ' ' || s[x] == '\t')
		x++;
	y = x;
	while(s[x] && s[x] != ' ' && s[x] != '\t')
		x++;
	while(s[x])
	{
		if(s[x] && s[x] != ' ' && s[x] != '\t' && (s[x - 1] == ' ' || s[x - 1] == '\t'))
		{
			while(s[x] && s[x] != ' ' && s[x] != '\t')
				write(1, &s[x++], 1);
			write(1, " ", 1);
		}
		x++;
	}
	while(s[y] && s[y] != ' ' && s[y] != '\t')
		write(1, &s[y++], 1);
}

int		main(int argc, char *argv[])
{
	if(argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}