/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:51:27 by daelee            #+#    #+#             */
/*   Updated: 2020/02/13 02:18:44 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (max <= min)
	{
		*range = (void *)0;
		return (0);
	}
	arr = (int*)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
	{
		*range = (void *)0;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (i);
}
