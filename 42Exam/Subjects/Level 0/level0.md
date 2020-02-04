# level 0

#### 1. aff_a.c

Write a program that takes a string, and displays the first 'a' character it
encounters in it, followed by a newline. If there are no 'a' characters in the
string, the program just writes a newline. If the number of parameters is not
1, the program displays 'a' followed by a newline.

```c
Example:

$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
```

```c
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac != 2) //av를 무조건 하나만 받겠다는 의미. 
		write(1, "a\n", 2);
	else
	{
		while (av[1][i])
		{
			if (av[1][i] != 'a')
				i++;
			else
			{
				write(1, "a", 1);
				break;
			}
		}
		write(1, "\n", 1);
	}
	return (0);
}
```



#### 3. aff_first_param.c 

Write a program that takes strings as arguments, and displays its first
argument followed by a \n.

If the number of arguments is less than 1, the program displays \n.

```
Example:

$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent$
$> ./aff_first_param "j'aime le fromage de chevre" | cat -e
j'aime le fromage de chevre$
$> ./aff_first_param
$
```

```c
#include <unistd.h>

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while (av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```

> 중요 포인트 >> 널을 같이 출력하지말고 예외케이스랑 합쳐서 생각



#### 4. aff_last_param.c

Write a program that takes strings as arguments, and displays its last
argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

```
Examples:

$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats$
$> ./aff_last_param "j'aime le savon" | cat -e
j'aime le savon$
$> ./aff_last_param
$
```

```c
#include <unistd.h>

int		main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 1)
	{
		while (av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```

 



#### 5. ft_countdown.c  

Write a program that displays all digits in descending order, followed by a
newline.

```c
Example:
$> ./ft_countdown | cat -e
9876543210$
$>
```

```c
#include <unistd.h>
int main(void)
{
	write (1, "9876543210\n", 11);
	return (0);
}


```



#### 6.  ft_print_numbers.c 

```c
#include <unistd.h>

void	ft_print_numbers(void)
{
	write (1, "0123456789", 10);
}
```



#### 7. hello.c

```c
#include <unistd.h>

int main (void)
{
	write(1, "Hello World!\n", 13);
}
```

   

#### 8. maff_alpha.c 

Write a program that displays the alphabet, with even letters in uppercase, and
odd letters in lowercase, followed by a newline.

```c
#include <unistd.h>

int		main(void)
{
	write(1, "aBcDeFgHiJkLmNoPqRsTuVwXyZ\n", 27);
	return (0);
}
```



#### 9. only_a.c

Write a program that displays a 'a' character on the standard output.

```
#include <unistd.h>

int		main(void)
{
	write(1, "a", 1);
	return (0);
}
```

