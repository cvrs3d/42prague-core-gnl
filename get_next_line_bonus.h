/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:48:04 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/04 13:45:57 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct fd_list
{
	int				fd;
	unsigned char	b[BUFFER_SIZE + 1];
	struct fd_list	*next;
}		t_fd_list;
int		contains(unsigned char *str, char chr);
int		bytelen(unsigned char *line);
void	ft_memmove(unsigned char *d, unsigned char *s, int n);
char	*get_next_line(int fd);

#endif
