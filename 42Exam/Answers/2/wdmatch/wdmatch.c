/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:26:59 by exam              #+#    #+#             */
/*   Updated: 2018/06/21 11:34:58 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int x = 0;
	int y = 0;
	int z = 0;
	while(s1[z])
		z++;
	while(s2[y])
	{
		if(s2[y] == s1[x])
		{
			x++;
		}
		y++;
	}
	if(z == x)
	{
		write(1, s1, x);
	}
}

int		main(int argc, char **argv)
{
	if(argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return 0;
}
