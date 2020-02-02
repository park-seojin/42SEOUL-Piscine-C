#include "ft_ultimate_ft.c"

int main()
{
	int i = 123;
	int *pi = &i;
	int **ppi = &pi;
	int ***pppi = &ppi;
	int ****ppppi = &pppi;
	int *****pppppi = &ppppi;
	int ******ppppppi = &pppppi;
	int *******pppppppi = &ppppppi;
	int ********ppppppppi = &pppppppi;
	int *********pppppppppi = &ppppppppi;

	ft_ultimate_ft(pppppppppi);
	return 0;
}
