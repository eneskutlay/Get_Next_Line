/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <ekutlay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:26:00 by ekutlay           #+#    #+#             */
/*   Updated: 2022/05/28 05:52:35 by ekutlay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

size_t  ft_strlen(char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char	  *ft_read_to_left_str(int fd, char *left_str);
char	  *ft_get_line(char *left_str);
char    *ft_new_left_str(char *left_str);
char	  *get_next_line(int fd)
#endif