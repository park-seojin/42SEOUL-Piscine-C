#include <unistd.h>

void	epur_str(char *s)
{
	int x = -1;
	
	while(*s != '\0')
	{
		while(*s == ' ' || *s == '\t')
			s++;
		if(x != -1 && *s != '\0')
			write(1, " ", 1);
		x = 0;
		while(s[x] != ' ' && s[x] != '\t' && s[x] != '\0')
			x++;
		write(1, s, x);
		s += x;
	}
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}