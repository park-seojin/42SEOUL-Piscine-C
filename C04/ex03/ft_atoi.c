/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:40:28 by daelee            #+#    #+#             */
/*   Updated: 2020/02/03 19:04:19 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_minus(int *i, char *str)
{
	int num_of_minus;

	num_of_minus = 0;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			num_of_minus++;
		(*i)++;
	}
	if (num_of_minus % 2 == 1)
		return (-1);
	else
		return (1);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = is_minus(&i, str);
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
