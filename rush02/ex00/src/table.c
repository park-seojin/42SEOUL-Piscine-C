/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:52:47 by dochoi            #+#    #+#             */
/*   Updated: 2020/02/09 22:18:44 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

#include "ft_str.h"

/*
** <hash fucntion>.
** String to int (0 ~ MAX_TABLE_SIZE -1).
** In order to assgin index.
*/

int		hash(const char *str)
{
	int	hash;
	int	a;

	hash = 0;
	a = 33;
	while (*str != '\0')
	{
		hash += (hash * a + (int)(*str)) % MAX_TABLE_SIZE;
		str++;
	}
	return (hash % MAX_TABLE_SIZE);
}

/*
** <insert fucntion>
** insert <str, value> into array.
** using <has funcion>, get an index.
** insert t_node into array[index].
** if it's not empty, insert in list format into arry[index]
*/

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
			temp->value = ft_strdup(value);
			temp->key = ft_strdup(str);
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

/*
** <find function>
** find "value" using "str" in array
*/

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

/*
** <create table function>
** make a MAX_TABLE_SIZE-sized table.
** Reset all struct members' value to zero
*/

t_node	*create_table(void)
{
	int		i;
	t_node	*t_node_array;

	i = 0;
	t_node_array = (t_node*)malloc(sizeof(t_node) * MAX_TABLE_SIZE);
	while (i < MAX_TABLE_SIZE)
	{
		t_node_array[i].key = 0;
		t_node_array[i].value = 0;
		t_node_array[i].next = 0;
		i++;
	}
	return (t_node_array);
}
