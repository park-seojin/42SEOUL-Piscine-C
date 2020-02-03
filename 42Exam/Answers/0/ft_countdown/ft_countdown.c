/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:06:12 by exam              #+#    #+#             */
/*   Updated: 2018/03/16 15:10:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int x)
{
	write(1, &x, 1);
}

void	ft_countdown()
{
	int x = '9';
	while(x >= '0')
	{
		ft_putchar(x);
		x--;
	}
}

int	main()
{
	ft_countdown();
	ft_putchar('\n');
	return	0;
}
