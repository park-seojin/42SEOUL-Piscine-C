/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:11:54 by byukim            #+#    #+#             */
/*   Updated: 2020/02/12 21:54:18 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_charset(char c, char *charset)
{
	int i;
	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_row(char *str, char *charset)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !(ft_is_charset(str[i], charset)))
		{
			count++;
			while (str[i] && !(ft_is_charset(str[i], charset)))
				i++;
		}
	}
	return (count);
}

int		ft_vector(char *str, char *charset, int i)
{
	int vec;
	vec = 0;
	while (str[i] && ft_is_charset(str[i], charset))
		i++;
	while (str[i] && !(ft_is_charset(str[i], charset)))
	{
		vec++;
		i++;
	}
	return (vec);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		vec;
	int		row;
	dest = (char **)malloc((sizeof(char *) * (ft_row(str, charset) + 1)));
	i = 0;
	row = 0;
	while (str[i])
	{
		vec = 0;
		dest[row] = (char *)malloc(sizeof(char) *
				(ft_vector(str, charset, i) + 1));
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		while (str[i] && !(ft_is_charset(str[i], charset)))
			dest[row][vec++] = str[i++];
		dest[row][vec] = '\0';
		row++;
	}
	dest[row] = 0;
	return (dest);
}
