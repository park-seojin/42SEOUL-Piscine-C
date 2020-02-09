/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:13:30 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 21:32:15 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

#include "ft_array.h"
#include "ft_str.h"

#include <unistd.h>

void	ft_print_str(char *str, int stream)
{
	while (*str)
	{
		write(stream, str, 1);
		str++;
	}
}

void	ft_print_error(void)
{
	ft_print_str("Error\n", 2);
}

void	ft_print_dict_error(void)
{
	ft_print_str("Dict Error\n", 2);
}

void	ft_print_arr(t_array *arr)
{
	if (arr->str[ft_strlen(arr->str) - 1] == ' ')
		arr->str[ft_strlen(arr->str) - 1] = '\0';
	ft_print_str(arr->str, 1);
	ft_print_str("\n", 1);
}
