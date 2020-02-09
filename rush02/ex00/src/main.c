/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:51:14 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:20:17 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "ft_rush.h"
#include "table.h"
#include "ft_dict.h"
#include "ft_print.h"

void	free_resource(t_array *arr, t_node *table)
{
	free_array(table);
	ft_destroy_array(arr);
}

int		main(int argc, char *argv[])
{
	t_array	*arr;
	t_node	*table;
	int		option;

	if (argc < 2 || argc > 3)
	{
		ft_print_error();
		return (-1);
	}
	option = argc == 3;
	table = create_table();
	if (parsing_dict(table, "numbers.dict") == -1)
		return (-1);
	if (option && parsing_dict(table, argv[1]) == -1)
		return (-1);
	arr = ft_create_array();
	if (ft_get_result(arr, argv[1 + option], table) == -1)
	{
		free_resource(arr, table);
		return (-1);
	}
	ft_print_arr(arr);
	free_resource(arr, table);
	return (0);
}
