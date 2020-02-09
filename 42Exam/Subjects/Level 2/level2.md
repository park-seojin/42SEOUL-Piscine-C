# level 2

#### 1. alpha_mirror.c

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the *number of arguments is not 1 == av는 하나만 받을거다* display only a newline.

```c
Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
```

##### my solution

```c
#include <unistd.h>

int		main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if ('a' <= av[1][i] && av[1][i] <= 'z') //소문자
				av[1][i] = 'a' + 'z' - av[1][i];
			else if ('A' <= av[1][i] && av[1][i] <= 'Z') //대문자
				av[1][i] = 'A' + 'Z' - av[1][i];
			write(1, &(av[1][i]), 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```

> 미러 문제 핵심은 >> a + z - (바꿀 알파벳) 



#### 2. do_op.c

```c
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}
```



#### 3. ft_strcmp  *

- 두 개의 문자열을 비교한다.

- 이 함수는 각 문자열의 첫 번째 문자 부터 비교를 시작한다. 만일 같다면 두 문자가 다를 때 까지나 NULL 에 도달할 때 까지 계속 비교를 수행한다.

- Return Vlaue

  - 만일 두 문자열이 정확하게 일치한다면 0 을 리턴한다.

  - 일치하지 않을 경우, 일치 하지 않는 첫 번째 문자를 비교해 str1 이 str2 보다 크다면 0 보다 큰 값을 아니면 0 보다 작은 값을 리턴한다.

```c
int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
```

> 팁 >> 두 문자열이 둘 다 끝날때까지 비교. or연산자면 둘 중 하나만 참이어도 계속 돌아감.



#### 4. ft_atoi		*

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

`int	ft_atoi(const char *str);`

atoi 함수에 문자열을 넣어주면 정수가 반환됩니다. 

단, 문자열은 정수로 되어있어야 하며 알파벳 영문자, 특수 문자가 포함되면 해당 문자부터는 변환을 하지 않습니다. 

또한, 처음부터 숫자가 아니면 0으로 변환됩니다.

```c
283a → 283
283a30 → 283
283! → 283
283!30 → 283
a30 → 0
!30 → 0
abc → 0
!@# → 0
```

```c
int		ft_atoi(char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}
```

```
팁 >> 공백문자면 ++, 부호 중에서도 
```



#### 5. ft_strrev	*

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

`char    *ft_strrev(char *str);`

```c
char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = 0;
	while (str[len])
		len++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len - 1]; //마지막 널문자는 안바꾸기 때문에 -1
		str[len - 1] = tmp;
    i++;
    len--;
	}
	return (str);
}
```



#### 6. max		

Write the following function:

`int		max(int* tab, unsigned int len);`

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

```c
int		max(int *tab, unsigned int len)
{
	int		i;
	int		max_value;

	if (!tab)
		return (0);
	i = 0;
	while (len--)
	{
		if (tab[i] > tab[i + 1])
			max_value = tab[i];
		i += 1;
	}
	return (max_value);
}
```

> 팁 >> 버블정렬에서 j 부분만 반복한 꼴. 제일 큰 수 하나만 찾으면 되니까.





#### Inter.c

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

```c
Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
```

```c
#include <unistd.h>

void ft_inter(char *a, char *b)
{
	int i = 0;
	char arr[127];
	while (b[i]) // initilize all the index of the arr to offset (1) which exist in b string.
	{
		arr[(int)b[i]] = 1;
		i++;
	}
	i = 0;
	while (a[i]) // check all the index of the arr if it's offset (1) or (0)
	{
		if(arr[(int)a[i]])
		{
			write(1, &a[i], 1);
			arr[(int)a[i]] = 0; // reset the offset (0)
		}
		i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}
```



#### ft_strdup.c

- Reproduce the behavior of the function strdup (man strdup).

```c
#include <stdlib.h>

int				ft_strlen(char *src)
{
	int			i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(char *src)
{
	int			i;
	char		*newstr;

	newstr = (char*)malloc(ft_strlen(src) + 1);
	if (newstr == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
```



#### union.c

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

아규먼트 2개 받아서, 앞에서 안나왔던 문자들만 출력하는 문제.

```c
Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
```

```c
#include <unistd.h>

void	ft_comp(char *str, char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (str[(unsigned int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			str[(unsigned int)s1[i] = 1;
		}
		i++;
	}
}

void	ft_union(char *s1, char *s2)
{
	char	str[256] = {0};

	ft_comp(str, s1);
	ft_comp(str, s2);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return 0;
}
```

**이전에 나왔던 문자인지 확인하는 알고리즘** 

> 1.  str[255]라는 문자배열판 0으로 초기화 해서 만든다. 
> 2. s1[i]의 값을 인덱스로하는 str배열에서 값이 0이면 출력한 뒤 값을 1로 바꾼다. (이미 등장한 문자는 flag를 달아놓는 개념)
>    1. `str[(int)s1[i]`   >>  s[i] 은 문자니까 정수로 강제형변환을 시킨 뒤 그 정수를 새 문자배열판의 인덱스로 활용한다. 즉, a의 아스키값 97은, str[97]이 될 것이고 값은 기본 0, 이미 출력됐다면 1이 될 것.

```c
int		ft_compare(char *str, char c, int i)
{
	while(i >= 0)
	{
		i--;
		if(str[i] == c)
			return 1;
	}
	return 0;
}
```

이 알고리즘도 좋다. 배열만 받는게 아니라 기준이 되는 문자까지 받은 뒤 뒤로 가면서 확인.



wdmatch.c
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

```c
Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
```

```c
#include <unistd.h>

void ft_wdmatch(char *a, char *b)
{
	int j = 0; // counter for second string
	int i = 0; // counter for first string

	while ((a[i] && b[j]) != 0)
	{
		if (a[i] == b[j]) // if char in both the strings are same then proceed further
		{
			i++;
			j++;
			if (a[i] == '\0') // check if we reached the end point of first string
			{
				while (*a) // print the whole string
				{
					write (1, a, 1);
					a++;
				}
				return ;
			}
		}
		else
			j++;
	}
}

int main (int ac, char **av) // main driver function
{
	if (ac == 3)
	{
		ft_wdmatch(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}

```

> a[i]이 b에 있는지만 체크 -> 있으면 둘다 ++ 없으면 b만 ++
>
> a[i]가 b가 끝날때까지 없으면 

#### Last_word.c

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

```c
Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
```

```c
#include <unistd.h>

int		is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (is_space(av[1][i]) == 1)
			i--;
		while (av[1][i] && is_space(av[1][i]) == 0)
			i--;
		i++;
		while (av[1][i] && (is_space(av[1][i]) == 0))
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```

> 1. 문자열 끝까지 뒤로 감
> 2. i--; (널문자 제외)
> 3. 공백이 아닐때까지 앞으로 옴
> 4. 공백이 올때까지 앞으로 옴 
>    1. -> `av(1)(i) != '\0' 이면서 공백이 아닌 동안 i--;` 안 그러면 배열 밖으로까지 뒤로 가게돼서 쓰레기 값을 출력하게 된다.
> 5. i++; (문자부터 시작)
> 6. 다시 뒤로 가면서 공백 전까지 출력