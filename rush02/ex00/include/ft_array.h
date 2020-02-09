/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ina <ina@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:53:29 by ina               #+#    #+#             */
/*   Updated: 2020/02/09 16:41:02 by ina              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# define DEFAULT_ARRAY_SIZE 32

typedef struct		s_array
{
	int		size;
	char	*str;
}					t_array;

t_array				*ft_resize_array(t_array *arr);
t_array				*ft_create_array(void);
t_array				*ft_append_str(t_array *arr, char *str);
void				ft_destroy_array(t_array *arr);
t_array				*ft_append_str_with_space(t_array *arr, char *str);
t_array				*ft_append_char(t_array *arr, char c);

#endif
