/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:05:26 by daelee            #+#    #+#             */
/*   Updated: 2020/02/04 22:09:33 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i <= nb / i)
	{
		if (i == (nb / i) + (nb % i))
			return (i);
		i++;
	}
	return (0);
}
