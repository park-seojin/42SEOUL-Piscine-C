#include <stdio.h>
#include "ft_sort_int_tab.c"

int main()
{
    int arr[10] = { 8, 4, 2, 5, 3, 7, 10, 1, 6, 9 };
 
	ft_sort_int_tab(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
