#include "ft_strcapitalize.c"
#include <stdio.h>

int main()
{
	char arr[ ] = "salutAA, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(arr);
	printf("%s\n", arr);

	return 0;
}
