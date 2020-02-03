/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:21:34 by cnaude            #+#    #+#             */
/*   Updated: 2018/06/13 14:29:20 by cnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	int x = 0;
	
	while(str[x])
	{
		if(str[x] >= 'a' && str[x] < 'z')
		{
			ft_putchar(str[x] + 1);
		}
		else if(str[x] >= 'A' && str[x] < 'Z')
		{
			ft_putchar(str[x] + 1);
		}
		else if(str[x] == 'z')
		{
			ft_putchar('a');
		}
		else if(str[x] == 'Z')
		{
			ft_putchar('A');
		}
		else
		{
			ft_putchar(str[x]);
		}
		x++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		rotone(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}

