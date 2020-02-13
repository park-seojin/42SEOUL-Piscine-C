/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:26:12 by byukim            #+#    #+#             */
/*   Updated: 2020/02/12 22:36:21 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_FIRST
# define IS_FIRST
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char g_lines;
char g_empty;
char g_obstacle;
char g_full;

char	**ft_split(char *str, char *charset);
int		ft_vector(char *str, char *charset, int i);
int		ft_row(char *str, char *charset);
int		ft_is_charset(char c, char *charset);
int		power(int a, int b);
int		is_minus(char *str);
void	number_arr(char *str, char number[10]);
int		ft_atoi(char *str);
int		minimum(int a, int b, int c);
int		*find_BSQ(char **arr, int lines, char obstacle);

#endif
