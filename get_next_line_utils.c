/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:54:35 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:33 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_contains(char *str, char chr)
{
	if (str == NULL)
		return (0);
	while (*str != 0)
	{
		if (*str == chr)
			return (1);
		str++;
	}
	return (0);
}

void	ft_strncat(char	*dst, char *src, int n)
{
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && n > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return ;
}

void	ft_strcpy(char *dst, char *src)
{
	if (!dst || !src)
		return ;
	while (*src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}
