/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:45:01 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/03 12:44:12 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
size_t	ft_strlen(char *str);
int			ft_contains(char *str, char chr);
void		ft_strncat(char *src, char *dst, int bytes);
void		ft_strcpy(char *dst, char *src);

#endif
