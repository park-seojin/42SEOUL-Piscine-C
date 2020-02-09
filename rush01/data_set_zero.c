/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:46:20 by daelee            #+#    #+#             */
/*   Updated: 2020/02/02 16:46:26 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	data_set_zero(char data[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			data[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	put_argv(char *row, char *col, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 8)
	{
		col[j] = argv[1][i];
		row[j] = argv[1][i + 16];
		j++;
		i += 2;
	}
}
