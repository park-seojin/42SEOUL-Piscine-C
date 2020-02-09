/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:09:04 by jinbkim           #+#    #+#             */
/*   Updated: 2020/02/02 16:34:46 by ckang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void		print_all(int row, int col, char data[row][col]);
extern int		is_not_error(int row, int col, char data[row][col]);
extern void		data_set_zero(char data[4][4]);
extern void		put_argv(char *row, char *col, char **argv);
extern void		check_zero_col(int any, char data[4][4]);
extern void		check_zero_row(int any, char data[4][4]);
extern void		check_last_num(int any1, int any2, char data[4][4], char cpt);
extern int		count_num(int row, int col, char data[4][4], char num);
extern void		check_col_down(char *col, char data[4][4]);
extern void		check_col_up(char *col, char data[4][4]);
extern void		check_row_right(char *row, char data[4][4]);
extern void		check_row_left(char *row, char data[4][4]);

void			skyscraper(char **argv)
{
	char	data[4][4];
	char	row[8];
	char	col[8];
	int		cpt;

	data_set_zero(data);
	put_argv(row, col, argv);
	check_row_left(row, data);
	check_row_right(row, data);
	check_col_up(col, data);
	check_col_down(col, data);
	cpt = 0;
	while (cpt <= 16)
	{
		check_last_num(4, 4, data, '0');
		check_zero_row(0, data);
		check_zero_col(0, data);
		cpt++;
	}
	if (is_not_error(4, 4, data) == 1)
	{
		print_all(4, 4, data);
	}
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
	}
	skyscraper(argv);
}
