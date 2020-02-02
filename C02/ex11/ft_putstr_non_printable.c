/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:54:24 by daelee            #+#    #+#             */
/*   Updated: 2020/01/28 16:24:11 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(unsigned char n)
{
	char *hex;

	hex = "0123456789abcdef";
	if (n > 16)
	{
		ft_print_hex(n / 16);
		ft_print_hex(n % 16);
	}
	else
		ft_putchar(hex[n]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((0 <= str[i] && str[i] <= 31) || ((unsigned char)str[i] >= 127))
		{
			ft_putchar('\\');
			if ((unsigned char)str[i] < 16)
			{
				ft_putchar('0');
			}
			ft_print_hex((unsigned char)str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}
