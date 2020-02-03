/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:10:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/30 15:22:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	search_and_replace(char *s1, char *s2, char *s3)
{
	int x = 0;
	while(s1[x])
	{
		if(s1[x] == s2[0])
		{
			s1[x] = s3[0];
		}
		x++;
	}
	write(1, s1, x);
}



int	main(int argc, char **argv)
{
	if(argc == 4)
	{
		search_and_replace(argv[1], argv[2], argv[3]);
	}
	write(1, "\n", 1);
	return 0;
}
