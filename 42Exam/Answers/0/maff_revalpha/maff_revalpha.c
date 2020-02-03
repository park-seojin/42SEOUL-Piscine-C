/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:13:22 by exam              #+#    #+#             */
/*   Updated: 2018/03/16 15:18:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}
void	maff_alpha()
{
	char x = 'z';
	char y = 'Y';
	while(x >= 'a' && y >= 'A')
	{
		ft_putchar(x);
		ft_putchar(y);
		x -= 2;
		y -= 2;
	}
}

int main()
{
	maff_alpha();
	ft_putchar('\n');
	return 0;
}
