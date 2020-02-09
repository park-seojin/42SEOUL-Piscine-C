## Rush02

1. 파일 열고 유효한 파일인지, 내가 읽는 라인들이 유효한 라인인지 확인해서 error처리

2. 딕셔너리 읽고 파싱해서 받은 숫자 문자열 처리 및 변환해서 출력



#### open()

```c
int open(const char *pathname, int flag, mode_t mode); 
```

- **pathname** : 파일의 경로와 이름입니다. 절대경로의 파일명을 주어도 되고 상대경로의 파일명을 주어도 됩니다.

- **flags** : 파일을 어떻게 열지를 결정합니다. 읽기 전용으로 열때는 `O_RDONLY`, 쓰기 전용으로 열때는 `O_WRONLY`, 읽기 쓰기로 열고 싶을때는 `O_RDWR`을 사용합니다. 여러개의 flag들을 사용하고 싶을때는 | (OR) 연산을 사용합니다. 예를 들어 읽기 쓰기 모드로 열고 싶은데 파일이 없으면 생성하는 flag는 `O_RDWR | O_CREAT`로 사용하면 됩니다.

- **mode** : 파일을 생성할때의 권한을 주는 옵션입니다. 만약 0777을 주게 된다면 모두 읽기, 쓰기, 실행 권한을 주게 되는 것이죠. 또한 가독성을 높이기 위해 심볼릭 상수도 제공하고 있습니다. 심볼릭 상수를 사용할때 역시 | 연산으로 권한을 줄 수 있습니다.

- **반환값** : 성공적으로 파일을 열게되면 ***파일 디스크립터를 반환***합니다. 그렇지 않으면 음수를 반환. 파일 사용이 끝나면 close()함수를 통해 파일을 닫아주어야 한다.

> ##### **파일 디스크립터 (File Descriptor)**
>
> 리눅스에서 파일을 읽고 쓰기 위해서는 반드시 파일을 Open 해야만 한다. 파일이 오픈되고 나면 파일 디스크립터라는 일종의 Index 번호가 반환되며, 이 값은 파일을 오픈한 프로세스의  고유 번호라 생각하면 이해하기 쉬울 것이다. 파일 디스크립터는 C int 타입으로 표현되며, 최대값은 1,024이지만 1,048,576번까지 설정할 수 있다. 또한, 프로세스마다 관례적으로 0,1,2번은 사전 배정되어 있는데 각각 번호별 의미는 다음과 같다.
>
> 0 : 표준 입력 (stdin) / 1 : 표준 출력 (stdout) / 2 : 표준 오류 (stderr)
>
> 따라서 실제 하나의 파일을 생성하게 되면 “3번” 부터 File Descriptor가 부여된다.



#### read()

```c
ssize_t read(int fd, void* buf, size_t len);
>> “fd가 바라보고 있는 파일에서 len길이 만큼을 buf에 읽어 들인다” 
```

- **fd** : 파일 디스크립터입니다. open은 정상적으로 파일을 열면 그 파일에 파일디스크립터를 반환하죠? 그 파일디스크립터를 써주면 됩니다. 하지만 표준 입력과 표준 출력, 표준 에러는 각각 순서대로 0, 1, 2가 되므로 표준 입력으로 읽어들일때는 0을 써주면 됩니다.
- **buf** : 파일에서 읽어들일 버퍼를 말하고 있습니다. 어떤 자료형으로 읽어올지 모르므로 void*로 매개변수로 받습니다.
- **len** : 얼마만큼 읽어올지를 결정합니다.
- **반환값** : 정상적으로 파일에 대한 내용을 읽어온다면 읽은 바이트수를 반홥합니다. 즉 ***len의 값을 반환***하죠. 그렇지 않다면 0을 반환합니다.

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:12:57 by daelee            #+#    #+#             */
/*   Updated: 2020/02/09 16:29:07 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "dochoi.h"
#include "ft_array.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_dict(char *line)
{
	int i;

	i = 0;
	if (!('0' <= line[0] && line[0] <= '9'))
		return(0);
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	if (line[i] != ' ' && line[i] != ':')
		return (0);
	while (line[i] == ' ')
		i++;
	if (line[i] == ':')
		i++;
	while (line[i] == ' ')
		i++;
	if (!(32 <= line[i] && line[i] <= 127))
		return (0);
	while (32 <= line[i] && line[i] <= 127)
		i++;
	if (line[i] != '\0')
		return (0);
	return (1);
}

int		parsing_line(t_node *array, char *line)
{
	char *key;
	char *value;
	int i;
	int j;
	int k;

	key = (char *)malloc(1000);
	value = (char *)malloc(1000);
	i = 0;
	j = 0;
	k = 0;
	if (check_dict(line) == 0)
		return (-1);
	while (line[i] == ' ')
		i++;
	while ('0' <= line[i] && line[i] <= '9')
		key[j++] = line[i++];
	while (line[i] == ' ' || line[i] == ':')
		i++;
	while (32 <= line[i] && line[i] <= 127)
		value[k++] = line[i++];
	line[0] = '\0';
	insert(array, key, value);
	return (1);
}

int		main(int ac, char **av)
{
	char *buf;
	int fd;
	char *line;
	int	i;


	t_node	*t_node_array;
	i = 0;
	t_node_array = (t_node*)malloc(sizeof(t_node) * 1224);
	while (i < 1224)
	{
		t_node_array[i].key = 0;
		t_node_array[i].value = 0;
		t_node_array[i].next = 0;
		i++;
	}
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		write(1, "file open error\n", 16);
	line = (char *)malloc(2000);
	i = 0;
	buf = (char*)malloc(sizeof(char));
	while(read(fd, buf, 1))
	{
		if (buf[0] == '\n')
		{
			if (ft_strlen(line) > 1)
				if (parsing_line(t_node_array, line) == -1)
				{
					write(1, "Dict Error\n", 11);
					break ;
				}
			i = 0;
			continue ;
		}
		line[i] = buf[0];
		i++;
	}
	if (ft_strlen(line) >  1)
		if (parsing_line(t_node_array, line) == -1)
		{
			write(1, "Dict Error\n", 11);
		}
	printf("%s\n", find(t_node_array, "0"));
	printf("%s\n", find(t_node_array, "100"));
	printf("%s\n", find(t_node_array, "50"));
	printf("%s\n", find(t_node_array, "19"));
}
```

