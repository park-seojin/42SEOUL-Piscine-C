/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:26:33 by daelee            #+#    #+#             */
/*   Updated: 2020/02/05 13:28:44 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int n)
{
	int x;
	int j;

	x = 1;
	j = 50;
	if (n == 1)
		return (1);
	while (j > 0)
	{
		x = (x + (n / x)) / 2;
		j--;
	}
	return (x);
}

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= ft_sqrt(nb))
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}
