/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dochoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:52:47 by dochoi            #+#    #+#             */
/*   Updated: 2020/02/09 02:12:58 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dochoi.h"
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (1);
	while (1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
	}
	return (0);
}

int		hash(const char *str)
{
	int	hash;
	int	a;

	hash = 0;
	a = 33;
	while (*str != '\0')
	{
		hash += (hash * a + (int)(*str)) % MAX_TABLE;
		str++;
	}
	return (hash % MAX_TABLE);
}

void	insert(t_node *array, char *str, char *value)
{
	int			idx;
	t_node		*ptr;
	t_node		*temp;

	idx = hash(str);
	temp = &array[idx];
	while (1)
	{
		if (!(ft_strcmp(temp->key, str)) || array[idx].key == 0)
		{
			temp->value = value;
			temp->key = str;
			return ;
		}
		if (temp->next == 0)
			break ;
		temp = temp->next;
	}
	ptr = (t_node*)malloc(sizeof(t_node));
	ptr->value = value;
	ptr->next = 0;
	ptr->key = str;
	temp->next = ptr;
}

char	*find(t_node *array, char *str)
{
	int		idx;
	t_node	*ptr;

	idx = hash(str);
	ptr = &array[idx];
	if (!ft_strcmp(ptr->key, str))
		return (ptr->value);
	while (1)
	{
		if (!ft_strcmp(ptr->key, str))
			return (ptr->value);
		ptr = ptr->next;
		if (ptr == 0)
			break ;
	}
	return (0);
}

