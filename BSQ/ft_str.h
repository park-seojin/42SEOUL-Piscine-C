/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:23:07 by daelee            #+#    #+#             */
/*   Updated: 2020/02/12 23:16:14 by daelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STR_H
# define _FT_STR_H

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strcat(char *dest, char *src);
int		ft_is_only_zero_n(char *str, int n);
int		ft_strcmp(char *s1, char *s2);
int		is_number(char *str);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int n);

#endif
