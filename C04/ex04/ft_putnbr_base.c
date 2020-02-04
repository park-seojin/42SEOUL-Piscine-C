/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:46:25 by daelee            #+#    #+#             */
/*   Updated: 2020/02/03 18:49:25 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
				|| base[i] == '\n' || base[i] == '\v' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == ' ')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

void	print_base(int nbr, int len, char *base)
{
	if (nbr < len)
	{
		ft_putchar(base[nbr % len]);
	}
	else
	{
		print_base((nbr / len), len, base);
		print_base((nbr % len), len, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = check_base(base);
	if (len > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			print_base((nbr / len) * -1, len, base);
			ft_putchar(base[nbr % len * -1]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			print_base(nbr * -1, len, base);
		}
		else
			print_base(nbr, len, base);
	}
}
