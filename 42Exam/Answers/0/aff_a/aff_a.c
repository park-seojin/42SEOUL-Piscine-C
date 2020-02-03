/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:01:54 by exam              #+#    #+#             */
/*   Updated: 2018/06/21 10:10:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	aff_a(char *str)
{
	int x = 0;

	while(str[x])
	{
		if(str[x] == 'a')
		{
			ft_putchar('a');
			break;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 2)
	{
		aff_a(argv[1]);
	}
	else
		ft_putchar('a');
	ft_putchar('\n');
	return 0;
}
