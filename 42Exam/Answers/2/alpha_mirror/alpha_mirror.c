/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:34:07 by exam              #+#    #+#             */
/*   Updated: 2018/06/21 12:42:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	alpha_mirror(char *str)
{
	int x = 0;
	while(str[x])
	{
		if(str[x] >= 'a' && str[x] <= 'z')
		{
			ft_putchar(('z' + 'a') - str[x]);
		}
		else if(str[x] >= 'A' && str[x] <= 'Z')
		{
			ft_putchar(('Z' + 'A') - str[x]);
		}
		else
			ft_putchar(str[x]);
		x++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 2)
	{
		alpha_mirror(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
