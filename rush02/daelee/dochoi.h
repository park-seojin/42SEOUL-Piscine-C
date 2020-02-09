/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dochoi.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:51:37 by dochoi            #+#    #+#             */
/*   Updated: 2020/02/09 15:58:58 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOCHOI_H
# define _DOCHOI_H

# include <stdlib.h>
# define MAX_TABLE 1223
typedef struct		s_node{
	char*			key;
	char*			value;
	struct s_node	*next;
}					t_node;
char	*find(t_node *array, char *str);
void	insert(t_node *array, char *str, char *value);
#endif
