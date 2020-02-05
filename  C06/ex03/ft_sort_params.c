/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:58:11 by daelee            #+#    #+#             */
/*   Updated: 2020/02/05 12:03:57 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	print_argv(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < (ac))
	{
		if (i + 1 < ac && ft_strcmp(av[i], av[i + 1]) > 0)
		{
			av[ac + 1] = av[i];
			av[i] = av[i + 1];
			av[i + 1] = av[ac + 1];
			i = 0;
		}
		i++;
	}
	print_argv(ac, av);
	return (0);
}
