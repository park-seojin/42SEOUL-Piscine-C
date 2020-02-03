/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:46:49 by cnaude            #+#    #+#             */
/*   Updated: 2018/06/13 14:46:52 by cnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	maff_alpha()
{
	int x = 'a';
	int y = 'B';
	while(x < 'z' && y <= 'Z')
	{
		ft_putchar(x);
		ft_putchar(y);
		x += 2;
		y += 2;
	}
}

int main()
{
	maff_alpha();
	ft_putchar('\n');
	return 0;
}
