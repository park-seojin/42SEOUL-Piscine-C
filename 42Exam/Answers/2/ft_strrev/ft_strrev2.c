#include <stdio.h>

char	*ft_strrev(char *str)
{
	int x = 0;
	int count = 0;
	char temp;
	while(str[count])
	{
		count++;
	}
	while(count - 1 > x)
	{
		temp = str[x];
		str[x] = str[count - 1];
		str[count - 1] = temp;
		count--;
		x++;
	}
	return(str);
}

int		main(int argc, char **argv)
{
	
	if(argc == 2)
	{
	char *s = argv[1];
	printf("awe %s\n", ft_strrev(s));
	}
	printf("\n");
	return 0;
}