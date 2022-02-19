/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekutlay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:18:02 by ekutlay           #+#    #+#             */
/*   Updated: 2022/02/19 04:30:16 by ekutlay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *status)
{
	char	*buff;
	int		len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 1;
	while (is_newline(status) == 0 && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		status = ft_strjoin(status, buff);
	}
	free(buff);
	return (status);
}

char	*parse_line(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i++])
		if (str[i++] == '\n')
			break ; //return -> seg fail
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			res[i] = str[i];
			i++;
			break ;
		}
		res[i] = str[i];
	}
	res[i] = '\0';
	return (res);
}

char	*clear_status(char *status)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (status[i] && status[i] != '\n')
		i++;
	if (status[i] == '\0')
	{
		free(status);
		return (NULL);
	}
	res = malloc(sizeof(char) * ft_strlen(status) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (status[i])
		res[j++] = status[i++];
	res[j] = '\0';
	free(status);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*status;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = ft_read(fd, status);
	if (!status)
		return (NULL);
	res = parse_line(status);
	status = clear_status(status);
	return (res);
}
