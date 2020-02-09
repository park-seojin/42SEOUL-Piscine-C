/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:19:07 by dochoi            #+#    #+#             */
/*   Updated: 2020/02/09 22:18:55 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

#include <stdlib.h>

/*
** <free_array_list function>
** using when array[idx] has two or more items
*/

void	free_array_list(t_node *array)
{
	if (array->next == 0)
	{
		if (array->value != 0)
			free(array->value);
		if (array->key != 0)
			free(array->key);
		free(array);
		return ;
	}
	free_array_list(array->next);
	if (array->value != 0)
		free(array->value);
	if (array->key != 0)
		free(array->key);
	if (array->next != 0)
		free(array->next);
	free(array);
}

/*
** <free_array function>
** struct array makes freeable memory
*/

void	free_array(t_node *array)
{
	int		i;

	i = 0;
	while (i < MAX_TABLE_SIZE)
	{
		if (array[i].next != 0)
			free_array_list(array[i].next);
		if (array[i].value != 0)
			free(array[i].value);
		if (array[i].key != 0)
			free(array[i].key);
		if (array[i].next != 0)
			free(array[i].next);
		i++;
	}
	free(array);
}
