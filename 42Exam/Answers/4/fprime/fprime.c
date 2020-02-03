#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int x = 2;
	while(x < n)
	{
		if(n % x == 0)
		{
			printf("%d*", x);
			n /= x;
			x = 1;
		}
		x++;
	}
	printf("%d", x);	
}

int		main(int argc, char *argv[])
{
	if(argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}