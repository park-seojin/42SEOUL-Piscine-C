/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:16:54 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:36:35 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

#include "ft_array.h"
#include "ft_str.h"
#include "table.h"
#include "ft_print.h"

#include <stdlib.h>

int		ft_get_result(t_array *arr, char *input, t_node *table)
{
	char		*str;

	if (ft_strlen(input) == 0)
	{
		ft_print_error();
		return (-1);
	}
	if (is_number(input) == -1)
	{
		ft_print_error();
		return (-1);
	}
	if (ft_is_only_zero_n(input, ft_strlen(input)))
		return (ft_exception_zero(arr, table));
	str = ft_get_str_mul3(input);
	if (ft_make_output(arr, str, table) == -1)
	{
		ft_print_dict_error();
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int		ft_exception_zero(t_array *arr, t_node *table)
{
	if (!find(table, "0"))
	{
		ft_print_dict_error();
		return (-1);
	}
	ft_append_str(arr, find(table, "0"));
	return (0);
}

/*
** Convert all digit to output and put in an array.
*/

int		ft_make_output(t_array *arr, char *str, t_node *table)
{
	while (*str)
	{
		if (ft_is_only_zero_n(str, 3))
		{
			str += 3;
			continue;
		}
		ft_get_three_digits(arr, str[0], table);
		if (ft_get_two_digits(arr, str + 1, table) > 0)
			;
		else
			ft_get_digit(arr, str[2], table);
		if (ft_strlen(str) > 3)
			if (ft_get_unit(arr, ft_strlen(str + 2), table))
				return (-1);
		str += 3;
	}
	return (0);
}

/*
** When divided string by 3, make the rest zero.
*/

char	*ft_get_str_mul3(char *str)
{
	char	*result;
	int		diff;
	int		str_len;

	str_len = ft_strlen(str);
	diff = str_len % 3;
	result = (char *)malloc(sizeof(char) * (str_len + diff + 1));
	result[0] = '\0';
	if (diff)
		ft_strncpy(result, "00", diff % 2 + 1);
	ft_strcat(result, str);
	return (result);
}
