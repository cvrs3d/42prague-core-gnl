/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:50:37 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/03 13:27:56 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	append(char **r, char b[BUFFER_SIZE + 1], int bytes)
{
	char	*new_res;
	size_t	r_len;

	r_len = ft_strlen(*r);
	new_res = (char *)malloc(r_len + bytes + 1);
	printf("Memory allocated for new_res %ld\n", (r_len + bytes + 1));
	if (!new_res)
		return (-1);
	printf("String in append before strcpy: %s\n", *r);
	ft_strcpy(new_res, *r);
	printf("String after strcpy: %s\n", new_res);
	free(*r);
	ft_strncat(new_res, b, bytes);
	printf("String after strncat: %s\n", new_res);
	*r  = new_res;
	printf("What pointer *r contains after append: %s\n", *r);
	if (ft_contains(b, '\n'))
		return (1);
	printf("Append returning 0\n");
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
		printf("String at the start of managebuf: %s\n", b);
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
			printf("||| How buffer looks like when append is successful: %s\n", b);
			return ;
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
	printf("String in the main function: %s\n", result);
	result[0] = '\0';
	bytes = ft_strlen(buffer);
	if (bytes > 0)
	{
		printf("Buffer is not empty entered if clause in main with: %s\n", buffer);
		if (append(&result, buffer, bytes) == 1)
		{
			bytes = 0;
			while(buffer[bytes] && buffer[bytes] != '\n')
				bytes++;
			if (buffer[bytes] == '\n')
				bytes++;
			ft_strcpy(buffer, buffer + bytes);
			return (result);
		}
	}
	managebuffer(buffer, &result, fd);
	printf("Output >>>\n");
	return (result);
}
