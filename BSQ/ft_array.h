/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:21:01 by daelee            #+#    #+#             */
/*   Updated: 2020/02/12 21:36:36 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# define DEFAULT_ARRAY_SIZE 5000

typedef struct		s_array
{
	int		size;
	char	*str;
}					t_array;

t_array				*ft_resize_array(t_array *arr);
t_array				*ft_create_array(void);
t_array				*ft_append_str(t_array *arr, char *str);
void				ft_destroy_array(t_array *arr);
t_array				*ft_append_char(t_array *arr, char c);

#endif

