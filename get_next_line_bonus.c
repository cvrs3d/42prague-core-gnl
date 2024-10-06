/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:46:34 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/06 13:49:11 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	set_data(char *buffer, int fd)
{
	ssize_t	byteread;
	int		buflen;

	buflen = ft_strlen(buffer);
	if (buflen > 0)
		return (buflen);
	byteread = read(fd, buffer, BUFFER_SIZE);
	if (byteread == -1)
		return (-1);
	buffer[byteread] = '\0';
	return (byteread);
}

static int	get_data(char *buffer, char **res)
{
	char	*new;
	int		bytes;

	bytes = ft_linelen(buffer);
	if (bytes == 0)
		return (-1);
	new = (char *)malloc(ft_strlen(*res) + bytes + 1);
	if (!new)
		return (-1);
	ft_memmove(new, *res, ft_strlen(*res));
	ft_memmove(new + ft_strlen(*res), buffer, bytes);
	free(*res);
	*res = new;
	ft_memmove(buffer, buffer + bytes, ft_strlen(buffer) - bytes);
	if (ft_isnewline(*res))
		return (1);
	return (0);
}

static int	manage_buffer(char *b, char **r, int fd, t_fd_list **h)
{
	int		response;
	ssize_t	read_result;

	while (1)
	{
		response = get_data(b, r);
		if (response > 0)
			return (1);
		if (response == -1)
			return (-1);
		read_result = set_data(b, fd);
		if (read_result == -1)
			return (-1);
		if (read_result <= 0 && response == 0)
		{
			freenode(h, fd);
			return (1);
		}
		else if (read_result <= 0)
			return (-1);
	}
}

static char	*get_current_buffer(t_fd_list **from, int fd)
{
	t_fd_list	*current;
	t_fd_list	*new;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	current = *from;
	while (current)
	{
		if (current->fd == fd)
			return (current->buffer);
		current = current->next;
	}
	new = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buffer[0] = '\0';
	new->next = *from;
	*from = new;
	return (new->buffer);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list = NULL;
	char				*buffer;
	char				*result;
	int					response;

	buffer = get_current_buffer(&fd_list, fd);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
		response = set_data(buffer, fd);
	result = (char *)malloc(BUFFER_SIZE + 1);
	if (!result)
	{
		freenode(&fd_list, fd);
		return (NULL);
	}
	result[0] = '\0';
	response = manage_buffer(buffer, &result, fd, &fd_list);
	if (response == -1)
	{
		freenode(&fd_list, fd);
		free(result);
		return (NULL);
	}
	return (result);
}
