/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:04:03 by daelee            #+#    #+#             */
/*   Updated: 2020/01/28 19:54:08 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str, int i)
{
	if (str[i] == '\0')
	{
		return (1);
	}
	if (65 <= str[i] && str[i] <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_str_is_alpha(char *str, int i)
{
	if ((65 <= str[i] && str[i] <= 90) || (97 <= str[i] && str[i] <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		ft_str_is_numeric(char *str, int i)
{
	if ((48 <= str[i] && str[i] <= 57))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_uppercase(str, i) == 1)
		{
			str[i] = str[i] + 32;
		}
		if (ft_str_is_alpha(str, i) == 1)
		{
			if (ft_str_is_alpha(str, i - 1) == 0)
			{
				if (ft_str_is_numeric(str, i - 1) == 0)
				{
					str[i] = str[i] - 32;
				}
			}
		}
		i++;
	}
	return (str);
}
