#include "ft_rev_int_tab.c"
#include <stdio.h>

int main()
{
	int i = 0;

	int arr[ ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_rev_int_tab(arr, 10);

	while (i < 10)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	return 0;
}
