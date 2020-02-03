/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:20:18 by cnaude            #+#    #+#             */
/*   Updated: 2018/06/21 18:20:41 by cnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	aff_first_param(char *str)
{
	int x = 0;
	while(str[x])
	{
		ft_putchar(str[x]);
		x++;
	}
}

int	main(int argc, char **argv)
{
	if(argc >= 2)
	{
		aff_first_param(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}

