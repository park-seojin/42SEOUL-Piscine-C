/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:05:08 by exam              #+#    #+#             */
/*   Updated: 2018/06/14 10:12:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	first_word(char *str)
{
	int x = 0;

	while((str[x] == ' ') || (str[x] == '\n') || (str[x] == '\t'))
	{
		x++;
	}
	while((str[x] != ' ') && (str[x] != '\n') && (str[x] != '\t') && str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		first_word(argv[1]);
	}
	ft_putchar('\n');
	return 0;
}
