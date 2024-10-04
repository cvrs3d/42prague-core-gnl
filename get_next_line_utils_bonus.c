/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:02:13 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/04 17:38:07 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	bytelen(unsigned char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void	ft_memmove(unsigned char *d, unsigned char *s, int n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = d;
	s2 = s;
	if (s1 == s2)
		return ;
	if (s1 < s2 || s1 >= s2 + n)
	{
		while (n--)
			*s1++ = *s2++;
		*s1 = '\0';
	}
	else
	{
		s1 += n;
		s2 += n;
		while (n--)
			*(--s1) = *(--s2);
		*s1 = '\0';
	}
}

int	contains(unsigned char *str, char chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return (1);
		str++;
	}
	return (0);
}
