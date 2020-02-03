#include <unistd.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *reject)
{
	const char *s1 = s;
	const char *s2;

	while (*s1)
	{
		s2 = reject;
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == '\0')
				return (s1 - s);
		}
		s1++;
	}
	return (s1 - s);
}
