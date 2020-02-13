/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:00:59 by daelee            #+#    #+#             */
/*   Updated: 2020/02/06 16:23:06 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *src)
{
	int			i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(char *src)
{
	int			i;
	char		*newstr;

	newstr = (char*)malloc(ft_strlen(src) + 1);
	if (newstr == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
