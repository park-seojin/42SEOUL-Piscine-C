/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:12:57 by daelee            #+#    #+#             */
/*   Updated: 2020/02/11 12:31:17 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dict.h"

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_array.h"
#include "ft_str.h"
#include "table.h"
#include "ft_print.h"

/*
** Dictionary Validation
*/

int		check_dict(char *line)
{
	int i;

	i = 0;
	if (!('0' <= line[0] && line[0] <= '9'))
		return (0);
	while ('0' <= line[i] && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != ':')
		return (0);
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

/*
** Parse key and value values on a valid line
** Insert into the table.
*/

int		parsing_line(t_node *table, char *line)
{
	t_array	*key;
	t_array	*value;
	int		line_idx;

	key = ft_create_array();
	value = ft_create_array();
	line_idx = 0;
	if (check_dict(line) == 0)
	{
		ft_destroy_array(key);
		ft_destroy_array(value);
		return (-1);
	}
	while (line[line_idx] == ' ')
		line_idx++;
	while ('0' <= line[line_idx] && line[line_idx] <= '9')
		ft_append_char(key, line[line_idx++]);
	while (line[line_idx] == ' ' || line[line_idx] == ':')
		line_idx++;
	while (32 <= line[line_idx] && line[line_idx] <= 127)
		ft_append_char(value, line[line_idx++]);
	insert(table, key->str, value->str);
	ft_destroy_array(key);
	ft_destroy_array(value);
	return (1);
}

/*
** Open the file.
*/

int		parsing_dict(t_node *table, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free_array(table);
		ft_print_dict_error();
		return (-1);
	}
	if (read_dict(table, fd) == -1)
	{
		free_array(table);
		ft_print_dict_error();
		return (-1);
	}
	return (0);
}

/*
** Read the dictionary line by line.
** If there are more than two letters on the line, parse.
*/

int		read_dict(t_node *table, int input)
{
	char	*buf;
	t_array	*line;

	line = ft_create_array();
	buf = (char*)malloc(sizeof(char));
	while (read(input, buf, 1))
	{
		if (buf[0] == '\n')
		{
			if (ft_strlen(line->str) > 1
				&& parsing_line(table, line->str) == -1)
				break ;
			line->str[0] = '\0';
		}
		else
			ft_append_char(line, buf[0]);
	}
	free(buf);
	if (ft_strlen(line->str) > 1 && parsing_line(table, line->str) == -1)
	{
		ft_destroy_array(line);
		return (-1);
	}
	ft_destroy_array(line);
	return (0);
}
