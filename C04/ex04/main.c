#include "ft_putnbr_base.c"
#include <limits.h>

int		main()
{
	int nbr = -2147483648;
	char *base = "01";
	
	ft_putnbr_base(nbr, base);
	return 0;
}
