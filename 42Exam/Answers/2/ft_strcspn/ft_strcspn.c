#include <unistd.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char *s1 = s;
	const char *s2;

	while (*s1)
	{
		s2 = reject;
		while (*s2)
		{
			if (*s1 == *s2++)
				return (s1 - s);
		}
		s1++;
	}
	return (s1 - s);
}