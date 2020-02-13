/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:24:13 by daelee            #+#    #+#             */
/*   Updated: 2020/02/12 21:24:25 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

#include <stdlib.h>
#include "ft_str.h"

/*
** Create an array of 32 sizes.
*/

t_array		*ft_create_array(void)
{
	t_array *array;

	array = (t_array*)malloc(sizeof(t_array));
	array->size = DEFAULT_ARRAY_SIZE;
	array->str = (char *)malloc(sizeof(char) * array->size);
	array->str[0] = 0;
	return (array);
}

/*
** Resize the array size twice.
*/

t_array		*ft_resize_array(t_array *arr)
{
	char	*new_str;
	int		new_size;

	new_size = arr->size * 2;
	new_str = (char *)malloc(sizeof(char) * new_size);
	ft_strcpy(new_str, arr->str);
	free(arr->str);
	arr->str = new_str;
	arr->size = new_size;
	return (arr);
}

/*
** Frees allocations that were created
** via the preceding ft_create_array functions.
*/

void		ft_destroy_array(t_array *arr)
{
	free(arr->str);
	free(arr);
}

