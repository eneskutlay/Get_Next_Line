/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 03:55:54 by ekutlay           #+#    #+#             */
/*   Updated: 2022/02/19 04:22:40 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
int		is_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_read(int fd, char *status);
char	*parse_line(char *str);
char	*clear_status(char *status);
char	*get_next_line(int fd);

#endif
