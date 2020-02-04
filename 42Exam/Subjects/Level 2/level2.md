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
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
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

