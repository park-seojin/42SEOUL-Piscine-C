/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 10:13:32 by exam              #+#    #+#             */
/*   Updated: 2018/06/21 11:09:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr(int n)
{
	while (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	return ;
}

void	fizzbuzz()
{
	int x = 1;
	while(x >= 1 && x <= 100)
	{
		if((x % 3 == 0) && (x % 5 == 0))
			write(1, "fizzbuzz\n", 9);
		else if(x % 3 == 0)
			write(1, "fizz\n", 5);
		else if(x % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			ft_putnbr(x);
			write(1, "\n", 1);
		}
		x++;
	}
}


int	main()
{
	fizzbuzz();
	return 0;
}
