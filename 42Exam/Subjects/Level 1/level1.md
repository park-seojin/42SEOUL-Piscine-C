# level 1

#### 1. first_word.c 

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1(무조건 스트링 하나만 받음 == ac 는 2), or if there are no words, simply display
a newline.

```c
Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
```

```c
#include <unistd.h>

int		ft_isspace(int i)
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')
		return (1);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		while (ft_isspace((argv[1][i])))
				i++;
		while (!(ft_isspace(argv[1][i])) && argv[1][i])
			write(1, &argv[1][i], 1);
    	i++;
	}
	write(1, "\n", 1);
	return (0);
}
```



#### 2. ft_putstr.c 

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

`void	ft_putstr(char *str);`

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str++);
	}
}
```

 

#### 3. ft_strcpy.c 

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

`char    *ft_strcpy(char *s1, char *s2);`

```c
char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
```



#### 4. ft_strlen.c 

Write a function that returns the length of a string.

Your function must be declared as follows:

`int	ft_strlen(char *str);`

```c
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
```



#### 5. ft_swap.c 

```c
void	ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
```

   

#### 6. repeat_alpha.c

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

```c
Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
```

```c
#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int rep; // counter to count the alpha position in ascii table
	char c;
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = av[1][i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) // if it's a alpha
			{
				if (c >= 'a' && c <= 'z')
					rep = c - 'a';
				if (c >= 'A' && c <= 'Z')
					rep = c - 'A';
				while (rep > 0) // when the counter is greater then 0 then write it
				{
					write (1, &c, 1);
					rep--;
				}
			}
			write (1, &c, 1); // anyways write each word for one time.
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
```

> 중요 포인트 >> 모든 문자를 기본으로 한번씩 출력. 어떤 알파벳 - 'a'를 하면 반복해야하는 횟수 - 1이 나오기 때문. 
>



#### 7. rev_print.c

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

```c
Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
```

```c
#include <unistd.h>

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i;

		i = 0;
		while(argv[1][i])
			i++; //스트링 길이를 구한다.
		while(i > 0)
			write(1, &argv[1][i], 1);
    	i--;
	}
	write(1 ,"\n", 1);
	return (0);
}
```

 

#### 8. rot_13.c  

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

```c
Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 231 $ //마지막 알파벳 l
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
```

```c
#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	char	mvup;
	char	mvdwn;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			mvup = argv[1][i] + 13;
			mvdwn = argv[1][i] - 13;
			if (('A' <= argv[1][i] && 'M' >= argv[1][i])
				|| ('a' <= argv[1][i] && 'm' >= argv[1][i]))
				write(1, &mvup, 1);
			else if (('N' <= argv[1][i] && 'Z' >= argv[1][i])
				|| ('n' <= argv[1][i] && 'z' >= argv[1][i]))
				write(1, &mvdwn, 1);
			else
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
```

> 중요 포인트 >> 알파벳 13번째 문자 m을 기준으로 밑이면 +13, 같거나 위면 -13 
>



#### 9. rotone.c

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

```c
Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
```

```c
#include <unistd.h>

int main (int ac, char **av)
{
    int i = 0;

if (ac == 2)
{
    while (av[1][i])
    {
        if (av[1][i] >= 'a' && av[1][i] <= 'y')
            av[1][i] += 1;
        else if(av[1][i] >= 'A' && av[1][i] <= 'Y')
            av[1][i] += 1;
        else if(av[1][i] == 'Z' || av[1][i] == 'z')
            av[1][i] -=25;
        write (1, &av[1][i], 1);
      	i++;
    }
}
write(1, "\n", 1);
return (0);
}
```



#### 10. search_and_replace.c

##### Allowed functions: write, exit

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

```c
Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
```

```c
#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	if (ac == 4)
	{
		while (av[1][i] && av[2][1] == '\0' && av[3][1] == '\0') 
		{
			if (av[1][i] == av[2][0])
      {
				av[1][i] = av[3][0];
      }
      write(1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
```

> 중요 포인트 >> 인자로 받은 스트링이 캐릭터인지 확인하는 법 -> `av[2][1] =='\0' ` 
>



#### 11. ulstr.c

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

```c
Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$
```

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		index;

	index = 0;
	if (ac == 2)
	{
		while (av[1][index] != '\0')
		{
			if (av[1][index] >= 'A' && av[1][index] <= 'Z')
				ft_putchar(av[1][index] - 'A' + 'a');
			else if (av[1][index] >= 'a' && av[1][index] <= 'z')
				ft_putchar(av[1][index] - 'a' + 'A');
			else
				ft_putchar(av[1][index]);
			index++;
		}
	}
	ft_putchar('\n');
	return (0);
}
```

