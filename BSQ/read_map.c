/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:21:30 by daelee            #+#    #+#             */
/*   Updated: 2020/02/13 00:37:35 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_array.h"
#include "ft_str.h"
#include "BSQ.h"

char		**read_map(char *filename)
{
	int 	fd;
	char	*buf;
	t_array	*one_d_map;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0); //에러 메세지
	one_d_map = ft_create_array();
	buf = (char*)malloc(sizeof(char) * 5000 + 1);
	if (buf == NULL)
		return (0); //에러 메세지
	while (read(fd, buf, 5000))
		ft_append_str(one_d_map, buf);
	free(buf);
	map = ft_split(one_d_map->str, "\n");
	return (map);
}


/*
int		main(void)
{
	char **dest;
	int i;

	i = 0;
	dest = read_map("map");
	while (dest[i])
	{
		printf("%s\n",dest[i]);
		i++;
	}
	return (0);
}*/
