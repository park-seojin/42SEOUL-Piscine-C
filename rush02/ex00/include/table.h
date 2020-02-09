/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:51:37 by dochoi            #+#    #+#             */
/*   Updated: 2020/02/09 20:13:55 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TABLE_H
# define _TABLE_H

# include <stdlib.h>
# define MAX_TABLE_SIZE 1223

typedef struct		s_node{
	char			*key;
	char			*value;
	struct s_node	*next;
}					t_node;

int					hash(const char *str);
void				insert(t_node *array, char *str, char *value);
char				*find(t_node *array, char *str);
t_node				*create_table(void);

void				free_array(t_node *array);
void				free_array_list(t_node *array);
void				free_array(t_node *array);

#endif
