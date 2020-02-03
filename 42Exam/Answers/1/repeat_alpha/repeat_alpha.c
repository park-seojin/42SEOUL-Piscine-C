/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:38:51 by cnaude            #+#    #+#             */
/*   Updated: 2018/06/21 19:46:22 by cnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	int x = 0;

	while(str[x])
	{
		if(str[x] >= 'a' && str[x] <= 'z')
		{
			int i = 0;
			while(i <= str[x] - 'a')
			{
				ft_putchar(str[x]);
				i++;
			}

		}
		else if(str[x] >= 'A' && str[x] <= 'Z')
		{
			int j = 0;
			while(j <= str[x] - 'A')
			{
				ft_putchar(str[x]);
				j++;
			}
		}
		else
			ft_putchar(str[x]);
		x++;
	}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
	{
		repeat_alpha(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
