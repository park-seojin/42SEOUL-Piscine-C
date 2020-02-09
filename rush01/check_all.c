/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:18:51 by ckang             #+#    #+#             */
/*   Updated: 2020/02/02 16:36:00 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_row_left(char *row, char data[4][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (row[i] == '1' && row[i + 4] == '2')
			data[i][3] = '3';
		else if (row[i] == '2' && row[i + 4] == '3')
			data[i][1] = '4';
		if (row[i] == '4')
		{
			data[i][0] = '1';
			data[i][1] = '2';
			data[i][2] = '3';
			data[i][3] = '4';
		}
		else if (row[i] == '1')
			data[i][0] = '4';
		i++;
	}
}

void	check_row_right(char *row, char data[4][4])
{
	int i;

	i = 4;
	while (i < 8)
	{
		if (row[i] == '1' && row[i - 4] == '2')
			data[i - 4][0] = '3';
		else if (row[i] == '2' && row[i - 4] == '3')
			data[i - 4][2] = '4';
		if (row[i] == '4')
		{
			data[i - 4][3] = '1';
			data[i - 4][2] = '2';
			data[i - 4][1] = '3';
			data[i - 4][0] = '4';
		}
		else if (row[i] == '1')
			data[i - 4][3] = '4';
		i++;
	}
}

void	check_col_up(char *col, char data[4][4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (col[i] == '1' && col[i + 4] == '2')
			data[3][i] = '3';
		else if (col[i] == '2' && col[i + 4] == '3')
			data[1][i] = '4';
		if (col[i] == '4')
		{
			data[0][i] = '1';
			data[1][i] = '2';
			data[2][i] = '3';
			data[3][i] = '4';
		}
		else if (col[i] == '1')
			data[0][i] = '4';
		i++;
	}
}

void	check_col_down(char *col, char data[4][4])
{
	int i;

	i = 4;
	while (i < 8)
	{
		if (col[i] == '1' && col[i - 4] == '2')
			data[1][i - 4] = '3';
		else if (col[i] == '2' && col[i - 4] == '3')
			data[2][i - 4] = '4';
		if (col[i] == '4')
		{
			data[3][i - 4] = '1';
			data[2][i - 4] = '2';
			data[1][i - 4] = '3';
			data[0][i - 4] = '4';
		}
		else if (col[i] == '1')
			data[3][i - 4] = '4';
		i++;
	}
}
