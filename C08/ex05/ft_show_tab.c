/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:54:25 by daelee            #+#    #+#             */
/*   Updated: 2020/02/13 10:44:29 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_size(int size, int flag)
{
	char c;

	if (size == 0 && flag)
	{
		write(1, "0", 1);
		return (0);
	}
	c = size % 10 + '0';
	if (size > 0)
	{
		print_size(size / 10, 0);
		write(1, &c, 1);
	}
}

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *ptr)
{
	int i;

	i = 0;
	while (ptr[i].str)
	{
		print_str(ptr[i].str);
		print_size(ptr[i].size, 1);
		write(1, "\n", 1);
		print_str(ptr[i].copy);
		i++;
	}
}
