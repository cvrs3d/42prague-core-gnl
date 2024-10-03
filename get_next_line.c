/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:50:37 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/03 12:33:08 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append(char **r, char b[BUFFER_SIZE + 1], int bytes)
{
	char	*new_res;
	size_t	r_len;

	r_len = ft_strlen(*r);
	new_res = (char *)malloc(r_len + bytes + 1);
	if (!new_res)
		return (-1);
	ft_strcpy(new_res, *r);
	free(*r);
	ft_strncat(new_res, b, bytes);
	*r  = new_res;
	if (ft_contains(b, '\n'))
		return (1);
	return (0);
}

static int	readline(char buffer[BUFFER_SIZE + 1], int fd)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (-1);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

static void	managebuffer(char b[BUFFER_SIZE + 1], char **r, int fd)
{
	ssize_t	bytes_read;
	ssize_t	offset;

	while (1)
	{
		bytes_read = readline(b, fd);
		if (bytes_read <= 0)
			return ;
		bytes_read = ft_strlen(b);
		if (append(r, b, bytes_read) == 1)
		{
			offset = 0;
			while (b[offset] && b[offset] != '\n')
				offset++;
			if (b[offset] == '\n')
				offset++;
			ft_strcpy(b, b + offset);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			bytes;

	result = (char *)malloc(1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !result)
		return (NULL);
	result[0] = '\0';
	bytes = ft_strlen(buffer);
	if (bytes > 0)
	{
		if (append(&result, buffer, bytes) == 1)
			return (result);
	}
	managebuffer(buffer, &result, fd);
	return (result);
}
