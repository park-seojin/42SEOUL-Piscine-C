/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:19:11 by ckang             #+#    #+#             */
/*   Updated: 2020/02/02 16:37:15 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_num(int row, int col, char data[4][4], char num)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (data[i][j] == num)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_last_num(int any1, int any2, char data[4][4], char cpt)
{
	int i;
	int j;

	while (++cpt <= '4')
	{
		any1 = 0;
		any2 = 0;
		if (count_num(4, 4, data, cpt) == 3)
		{
			i = -1;
			while (++i < 4)
			{
				j = -1;
				while (++j < 4)
				{
					if (data[i][j] == cpt)
					{
						any1 += i;
						any2 += j;
					}
				}
			}
			data[6 - any1][6 - any2] = cpt;
		}
	}
}
