/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:06:34 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 20:17:50 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

# include "table.h"

int		ft_strlen(char *str);
int		check_dict(char *line);
int		parsing_line(t_node *table, char *line);
int		parsing_dict(t_node *table, char *filename);
int		read_dict(t_node *table, int input);

#endif
