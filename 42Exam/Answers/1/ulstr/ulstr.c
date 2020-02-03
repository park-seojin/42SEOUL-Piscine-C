/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 09:17:09 by exam              #+#    #+#             */
/*   Updated: 2018/04/07 09:23:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ulstr(char *str)
{
	int x = 0;
	while(str[x])
	{
		if(str[x] >= 'a' && str[x] <= 'z')
		{
			ft_putchar(str[x] - 32);
		}
		else if(str[x] >= 'A' && str[x] <= 'Z')
		{
			ft_putchar(str[x] + 32);
		}
		else
		{
			ft_putchar(str[x]);
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	if(argc == 2)
	{
		ulstr(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
