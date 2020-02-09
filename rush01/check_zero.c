/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:45:37 by daelee            #+#    #+#             */
/*   Updated: 2020/02/02 16:47:14 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_zero_row(int any, char data[4][4])
{
	int i;
	int j;
	int ch;
	int save;

	i = 0;
	while (i < 4)
	{
		j = 0;
		any = 0;
		ch = 0;
		while (j < 4)
		{
			ch = ch + data[i][j] - '0';
			if (data[i][j] == '0')
			{
				any++;
				save = j;
			}
			j++;
		}
		if (any == 1)
			data[j][save] = (10 - ch) + '0';
		i++;
	}
}

void	check_zero_col(int any, char data[4][4])
{
	int i;
	int j;
	int ch;
	int save;

	i = 0;
	while (i < 4)
	{
		j = 0;
		any = 0;
		ch = 0;
		while (j < 4)
		{
			ch = ch + data[i][j] - '0';
			if (data[i][j] == '0')
			{
				any++;
				save = j;
			}
			j++;
		}
		if (any == 1)
			data[save][i] = (10 - ch) + '0';
		i++;
	}
}
