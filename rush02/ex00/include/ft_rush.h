/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:10:27 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 22:27:53 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include "ft_array.h"
# include "table.h"

int		ft_get_result(t_array *arr, char *input, t_node *table);
int		ft_make_output(t_array *arr, char *str, t_node *table);
int		ft_exception_zero(t_array *arr, t_node *table);
char	*ft_get_str_mul3(char *str);

int		ft_get_three_digits(t_array *arr, char digit, t_node *table);
int		ft_get_two_digits(t_array *arr, char *digits, t_node *table);
int		ft_get_digit(t_array *arr, char digit, t_node *table);
int		ft_get_unit(t_array *arr, int power, t_node *table);

#endif
