#include <stdlib.h>
#include <stdio.h>
#include "ft_range.c"

int		*a(int min, int max)
{
	int	range;
	int	index;
	int	*buffer;

	if (min >= max)
		return (0);
	range = max - min - 1;
	if ((buffer = malloc(range * sizeof(int))) == NULL)
		return (0);
	index = 0;
	while (index <= range)
	{
		buffer[index] = min + index;
		index++;
	}
	return (buffer);
}

void	debug_dump_array(int numbers[], int size)
{
	int index;

	printf("[ ");
	index = 0;
	while (index < size)
	{
		printf("%d", numbers[index]);
		if (index != size - 1)
		{
			printf(", ");
		}
		index++;
	}
	printf(" ]");
}

int		main(void)
{
	int	min;
	int	max;

	min = -1212312314;
	max = -1241351433;
	printf("=====YOUR ANSWER=====\n");
	printf("min = %d, max = %d -> ", min, max);
	debug_dump_array(ft_range(min, max), max - min);
	printf("\n");
	printf("=====REAL ANSWER=====\n");
	printf("min = %d, max = %d -> ", min, max);
	debug_dump_array(a(min, max), max - min);
	printf("\n");
}

