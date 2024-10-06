/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:48:04 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/06 12:56:50 by yustinov         ###   ########.fr       */
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
	char			buffer[BUFFER_SIZE + 1];
	struct fd_list	*next;
}		t_fd_list;
char	*get_next_line(int fd);
void	freenode(t_fd_list **from, int fd);
void	ft_memmove(char *d, char *s, int n);
int		ft_linelen(char *str);
int		ft_isnewline(char *str);
size_t	ft_strlen(char *str);

#endif
