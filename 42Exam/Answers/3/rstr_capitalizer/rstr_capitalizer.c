#include <unistd.h>

void	rstr_capitalizer(char *s)
{
	int x = 0;
	while(s[x])
	{
		if(s[x + 1] == ' ' || s[x + 1] == '\t' || s[x + 1] == '\0')
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

	if(argc == 1)
		write(1, "\n", 1);	
	while(x < argc)
	{
		rstr_capitalizer(argv[x]);
		x++;
	}
	return 0;
}