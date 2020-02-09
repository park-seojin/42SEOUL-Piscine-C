/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:59:23 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:17:23 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

#include "ft_array.h"
#include "ft_str.h"
#include "table.h"

#include <stdlib.h>

/*
** <ft_get_three_digits funtion>
** three digit nubmerconvert to output
*/

int		ft_get_three_digits(t_array *arr, char digit, t_node *table)
{
	if (digit == '0')
		return (0);
	if (ft_get_digit(arr, digit, table) == -1)
		return (-1);
	if (ft_get_unit(arr, 3, table) == -1)
		return (-1);
	return (0);
}

/*
** <ft_get_two_digits funtion>
** two digit number convert to output
*/

int		ft_get_two_digits(t_array *arr, char *digits, t_node *table)
{
	char *str;

	if (digits[0] == '0')
		return (0);
	str = (char *)malloc(sizeof(char) * 3);
	if (!str)
		return (-1);
	ft_strncpy(str, digits, 2);
	if (str[0] == '1')
	{
		if (!find(table, str))
			return (-1);
		ft_append_str_with_space(arr, find(table, str));
		free(str);
		return (1);
	}
	str[1] = '0';
	if (!find(table, str))
		return (-1);
	ft_append_str_with_space(arr, find(table, str));
	free(str);
	return (0);
}

/*
** <ft_get_digit funtion>
** one digit number convert to output
*/

int		ft_get_digit(t_array *arr, char digit, t_node *table)
{
	char *str;

	if (digit == '0')
		return (0);
	str = (char *)malloc(sizeof(char) * 3);
	if (!str)
		return (-1);
	str[0] = digit;
	str[1] = '\0';
	if (!find(table, str))
		return (-1);
	ft_append_str_with_space(arr, find(table, str));
	free(str);
	return (0);
}

/*
** <ft_get_unit funtion>
** current digits number convert to output
*/

int		ft_get_unit(t_array *arr, int power, t_node *table)
{
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (power + 1));
	if (!result)
		return (-1);
	i = 1;
	result[0] = '1';
	while (i < power)
	{
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	if (!find(table, result))
		return (-1);
	ft_append_str_with_space(arr, find(table, result));
	free(result);
	return (0);
}
