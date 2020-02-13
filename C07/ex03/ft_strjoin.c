/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:05:38 by daelee            #+#    #+#             */
/*   Updated: 2020/02/12 12:26:49 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			argv_len(char **strs, int size)
{
	int		argvlen;
	int		i;

	i = 0;
	argvlen = 0;
	while (i < size)
	{
		argvlen = argvlen + ft_strlen(strs[i]);
		i++;
	}
	return (argvlen + 1);
}

char		*ft_strcat(char *newstr, char *strs)
{
	int		i;
	int		j;

	i = 0;
	while (newstr[i])
	{
		i++;
	}
	j = 0;
	while (strs[j])
	{
		newstr[i] = strs[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstr;
	int		sep_len;
	int		i;

	sep_len = ft_strlen(sep);
	if (size == 0)
	{
		newstr = malloc(sizeof(char));
		return (newstr);
	}
	else
	{
		newstr = (char*)malloc(argv_len(strs, size) + (sep_len * (size - 1)));
		newstr[argv_len(strs, size) + (sep_len * (size - 1))] = '\0';
		newstr[0] = '\0';
	}
	i = 0;
	while (i < size)
	{
		ft_strcat(newstr, strs[i]);
		if (i < size - 1)
			ft_strcat(newstr, sep);
		i++;
	}
	return (newstr);
}
