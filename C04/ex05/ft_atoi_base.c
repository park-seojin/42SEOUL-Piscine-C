/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 22:23:24 by daelee            #+#    #+#             */
/*   Updated: 2020/02/03 19:03:13 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
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

int		nbr_base(char *str, int len, char *base)
{
	int is_find;
	int nbr;
	int i;

	nbr = 0;
	while (*str != '\0')
	{
		is_find = 0;
		i = -1;
		while (base[++i] != '\0')
		{
			if (base[i] == *str)
			{
				is_find = 1;
				break ;
			}
		}
		if (is_find == 1)
			nbr = nbr * len + i;
		else
			break ;
		str++;
	}
	return (nbr);
}

int		ft_atoi_base(char *str, char *base)
{
	int	len;
	int sign;
	int num_of_minus;

	sign = 1;
	num_of_minus = 0;
	len = check_base(base);
	if (len < 2)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			num_of_minus++;
		str++;
	}
	if (num_of_minus % 2 == 1)
		sign = -1;
	return (sign * nbr_base(str, len, base));
}
