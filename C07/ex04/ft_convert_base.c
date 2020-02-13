/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:22:03 by daelee            #+#    #+#             */
/*   Updated: 2020/02/13 07:26:31 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

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
	if (i < 2)
		return (0);
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

char	*ft_basify(long long num, char *base_str)
{
	int		base_num;
	long long	digit;
	char	*result;
	long long		i;
	long long		target;
	long long		nbr;

	(num < 0) ? nbr = (num * -1) : (nbr = num);
	base_num = ft_strlen(base_str);
	target = nbr;
	digit = 0;
	while (target > 0)
	{
		digit++;
		target /= base_num;
	}
	result = (char *)malloc(sizeof(*result) * (digit + 1));
	i = digit - 1;
	if (num < 0)
	{
		result[i] = '\0';
		i--;
		result[i] = '\0';
	}
	while ((nbr < 0) ? (i > 0) : (i >= 0))
	{
		result[i] = base_str[nbr % base_num];
		nbr /= base_num;
		i--;
	}
	if (num < 0)
	{	
		result[--i] = '-';
	}
	free(result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int num;

	if (!*nbr || !check_base(base_from) || !check_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	printf("아토이는 %d\n", num);
	return (ft_basify(num, base_to));
}
