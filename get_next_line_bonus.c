/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:46:34 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/04 18:22:32 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 * Accepts a poiter to the head.
 * Checks if file descriptor is present
 * (Yes) Returns its node
 * (no) Creates a new node and appends it to the start;
 */
static t_fd_list	*get_current_node(t_fd_list **list, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new;

	if (fd < 0)
		return (NULL);
	current = *list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->b[0] = '\0';
	new->next = *list;
	*list = new;
	return (new);
}

static int	put_data(t_fd_list *to)
{
	ssize_t	bytes_read;

	bytes_read = read(to->fd, to->b, BUFFER_SIZE);
	if (bytes_read == 0)
		return (0);
	if (bytes_read < 0)
		return (-1);
	to->b[bytes_read] = '\0';
	return (1);
}

static int	remove_node(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*previous;

	current = *head;
	if (current && current->fd == fd)
	{
		*head = current->next;
		free(current);
		return (-1);
	}
	while (current)
	{
		if (current->next->fd == fd)
		{
			previous = current;
			previous->next = current->next->next;
			current = current->next;
			free(current);
			return (-1);
		}
		current = current->next;
	}
	return (-1);
}

/*
 * Reallocate result with additional memory for bytes in buffer;
 * Memmove bytes to the new result;
 * Free old one;
 * If it was \n terminated return 1 and shift remains;
 * Return 0 for next chunk;
 * Retunr -1 to handle error;
 */
static int	get_data_from(t_fd_list *from, unsigned char **to, t_fd_list **h)
{
	unsigned char	*new;
	int				response;

	new = (unsigned char *)malloc(bytelen(*to) + bytelen(from->b) + 1);
	if (!new)
		return (-1);
	ft_memmove(new, *to, bytelen(*to));
	ft_memmove(new + bytelen(*to), from->b, bytelen(from->b));
	free(*to);
	*to = new;
	if (contains(from->b, '\n'))
	{
		ft_memmove(from->b, from->b + bytelen(from->b),
			BUFFER_SIZE - bytelen(from->b));
		return (1);
	}
	response = put_data(from);
	if (response == 0 && bytelen(from->b) <= 0)
		return (remove_node(h, from->fd));
	if (response == -1)
		return (-1);
	return (0);
}

/*
 * getnline should call get_data_from
 * until EOF or '\n' is reached
`*/
char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list = NULL;
	unsigned char		*result;
	t_fd_list			*current;
	int					response;

	current = get_current_node(&fd_list, fd);
	result = (unsigned char *)malloc(1);
	if (!current || !result)
		return (NULL);
	result[0] = '\0';
	while (1)
	{
		response = get_data_from(current, &result, &fd_list);
		if (response == 1)
			return ((char *)result);
		if (response == -1)
		{
			free(result);
			return (NULL);
		}
	}
}
