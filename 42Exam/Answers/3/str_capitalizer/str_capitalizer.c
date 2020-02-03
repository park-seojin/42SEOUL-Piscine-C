#include <unistd.h>

void	str_capitalizer(char *s)
{
	int x = 0;

	while(s[x])
	{
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] -= 32;
		if(s[x - 1] == ' ' || s[x - 1] == '\t')
		{
			if(s[x] >= 'a' && s[x] <= 'z')
				s[x] -= 32;
		}
		else
			if(s[x] >= 'A' && s[x] <= 'Z')
				s[x] += 32;
		x++;
	}
	write(1, s, x);
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int x = 1;

	while(x < argc)
	{
		str_capitalizer(argv[x]);
		x++;
	}
	if(argc == 1)
		write(1, "\n", 1);
	return 0;
}