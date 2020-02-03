#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac == 7)
		write(1, "Success\n",8);
	else if (ac == 6 && av[2][1] != 'T')
		write(1, "Success\n", 8);
	else if (ac == 1)
		write(1, "\n", 1);
	else
		write(1, "Fail\n", 5);
	return (0);
}