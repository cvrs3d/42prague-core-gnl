/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:38:39 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/06 13:24:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isnewline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

void	ft_memmove(char *d, char *s, int n)
{
	char	*dst;
	char	*src;

	dst = d;
	src = s;
	if (dst == src)
		return ;
	if (dst < src || dst >= src + n)
	{
		while (n--)
			*dst++ = *src++;
		*dst = '\0';
	}
	else
	{
		dst += n;
		src += n;
		while (n--)
			*(--dst) = *(--src);
		*dst = '\0';
	}
	return ;
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	freenode(t_fd_list **from, int fd)
{
	t_fd_list	*current;
	t_fd_list	*previous;
	t_fd_list	*to_free;

	current = *from;
	if (current && current->fd == fd)
	{
		*from = current->next;
		free(current);
		return ;
	}
	while (current && current->next)
	{
		if (current->next->fd == fd)
		{
			previous = current;
			to_free = current->next;
			previous->next = to_free->next;
			free(to_free);
			return ;
		}
		current = current->next;
	}
}
