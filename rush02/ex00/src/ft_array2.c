/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:36:47 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:16:11 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

#include "ft_str.h"

/*
** Append a character to array in consideration of its size.
** Resize if array size is shortage.
*/

t_array		*ft_append_char(t_array *arr, char c)
{
	int arr_str_len;

	arr_str_len = ft_strlen(arr->str);
	while (arr_str_len + 3 >= arr->size)
		ft_resize_array(arr);
	arr->str[arr_str_len] = c;
	arr->str[arr_str_len + 1] = '\0';
	return (arr);
}

/*
** Append a string to array in consideration of its size.
** Resize if array size is shortage.
*/

t_array		*ft_append_str(t_array *arr, char *str)
{
	while (ft_strlen(arr->str) + ft_strlen(str) + 2 >= arr->size)
		ft_resize_array(arr);
	ft_strcat(arr->str, str);
	return (arr);
}

t_array		*ft_append_str_with_space(t_array *arr, char *str)
{
	ft_append_str(arr, str);
	ft_append_char(arr, ' ');
	return (arr);
}
