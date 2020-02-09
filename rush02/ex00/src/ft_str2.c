/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:19:54 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:18:16 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

#include <stdlib.h>

/*
** <ft_is_only_zero_n funtion>
** Determine if the string consists of zero in n size
** if it has not zero, return 0
** if it has only zero, return 1
*/

int		ft_is_only_zero_n(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

/*
** <ft_strcmp function>
** fucntions lexicographically compare the null-terminated string s1 and s2.
*/

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (1);
	while (1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
	}
	return (0);
}

/*
** <is_number function>
** Determine if the string consisits of numbers
*/

int		is_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*temp;

	len = ft_strlen(src);
	i = 0;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * (n + 1));
	if (!temp)
		return (0);
	while (src[i] && i < n)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
