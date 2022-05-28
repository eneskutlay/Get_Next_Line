/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <ekutlay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 05:26:16 by ekutlay           #+#    #+#             */
/*   Updated: 2022/05/28 05:52:09 by ekutlay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
