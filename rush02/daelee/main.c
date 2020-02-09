/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:12:57 by daelee            #+#    #+#             */
/*   Updated: 2020/02/09 16:40:46 by daelee           ###   ########.fr       */
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

